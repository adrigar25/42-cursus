#include "./libs/ft_printf/ft_printf.h"
#include "./libs/mlx/mlx.h"
#include "./so_long.h"
#include <stdlib.h>

int	finish_game(t_env *env)
{
	if (env->img_floor)
		mlx_destroy_image(env->mlx, env->img_floor);
	if (env->img_wall)
		mlx_destroy_image(env->mlx, env->img_wall);
	if (env->img_exit)
		mlx_destroy_image(env->mlx, env->img_exit);
	if (env->img_collectible)
		mlx_destroy_image(env->mlx, env->img_collectible);
	if (env->img_player)
		mlx_destroy_image(env->mlx, env->img_player);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->map)
		free_map(env->map);
	return (0);
}

void	open_window(t_env *env)
{
	if (!env->mlx)
		return ;
	env->win = mlx_new_window(env->mlx, env->win_width, env->win_height,
			"./so_long.c");
}

void	init_images(t_env *env)
{
	int	img_width;
	int	img_height;

	img_height = TILE_SIZE;
	img_width = TILE_SIZE;
	env->img_floor = mlx_xpm_file_to_image(env->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	env->img_wall = mlx_xpm_file_to_image(env->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	env->img_exit = mlx_xpm_file_to_image(env->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	env->img_collectible = mlx_xpm_file_to_image(env->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	env->img_player = mlx_xpm_file_to_image(env->mlx, "textures/player.xpm",
			&img_width, &img_height);
}
int	print_map(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (env->map[++y])
	{
		x = -1;
		while (env->map[y][++x])
		{
			if (env->map[y][x] == '1')
				mlx_put_image_to_window(env->mlx, env->win, env->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (env->map[y][x] == '0')
				mlx_put_image_to_window(env->mlx, env->win, env->img_floor, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (env->map[y][x] == 'P')
				mlx_put_image_to_window(env->mlx, env->win, env->img_player, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (env->map[y][x] == 'C')
				mlx_put_image_to_window(env->mlx, env->win,
					env->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (env->map[y][x] == 'E')
				mlx_put_image_to_window(env->mlx, env->win, env->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
		}
	}
	return (0);
}

void	get_player_position(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			if (env->map[y][x] == 'P')
			{
				env->player_x = x;
				env->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
void	move_player_to(t_env *env, int new_x, int new_y)
{
	if (env->map[new_y][new_x] != '1')
	{
		env->map[env->player_y][env->player_x] = '0';
		env->player_x = new_x;
		env->player_y = new_y;
		env->map[env->player_y][env->player_x] = 'P';
	}
}
int	key_handler(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		return (0);
	}
	if (keycode == 13) // W
		move_player_to(env, env->player_x, env->player_y - 1);
	else if (keycode == 0) // A
		move_player_to(env, env->player_x - 1, env->player_y);
	else if (keycode == 1) // S
		move_player_to(env, env->player_x, env->player_y + 1);
	else if (keycode == 2) // D
		move_player_to(env, env->player_x + 1, env->player_y);
	return (0);
}

int	start_game(char *map_file)
{
	t_env *env;

	if (!check_map_file(map_file))
		return (0);
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->map = open_map(map_file);
	if (!env->map || !check_map(env->map))
		return (finish_game(env));
	get_player_position(env);
	env->mlx = mlx_init();
	env->win_width = get_map_width(env->map) * TILE_SIZE;
	env->win_height = get_map_height(env->map) * TILE_SIZE;
	open_window(env);
	if (!env->win)
		return (finish_game(env));
	init_images(env);
	print_map(env);
	ft_printf("Posición inicial del jugador: (%d, %d)\n", env->player_x,
		env->player_y);
	mlx_hook(env->win, 2, 1L, key_handler, env);
	mlx_loop_hook(env->mlx, print_map, env);
	mlx_loop(env->mlx);
	finish_game(env);
	return (1);
}