/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 12:16:11 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	print_moves(t_env *env)
{
	char	*str;

	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, "number of moves:");
	str = ft_itoa(env->moves);
	if (str)
	{
		mlx_string_put(env->mlx, env->win, 130, 10, 0xFFFFFF, str);
		free(str);
	}
}

void	init_images(t_env *env)
{
	int	img_width;
	int	img_height;

	if (!env->win)
		finish_game(env);
	img_height = TILE_SIZE;
	img_width = TILE_SIZE;
	env->img_floor = mlx_xpm_file_to_image(env->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	env->img_wall = mlx_xpm_file_to_image(env->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	env->img_exit = mlx_xpm_file_to_image(env->mlx, "textures/exit_1.xpm",
			&img_width, &img_height);
	env->img_collectible = mlx_xpm_file_to_image(env->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	env->img_player_down = mlx_xpm_file_to_image(env->mlx,
			"textures/player_down.xpm", &img_width, &img_height);
	env->img_player_left = mlx_xpm_file_to_image(env->mlx,
			"textures/player_left.xpm", &img_width, &img_height);
	env->img_player_right = mlx_xpm_file_to_image(env->mlx,
			"textures/player_right.xpm", &img_width, &img_height);
	env->img_player_up = mlx_xpm_file_to_image(env->mlx,
			"textures/player_up.xpm", &img_width, &img_height);
	env->img_player_jump = mlx_xpm_file_to_image(env->mlx,
			"textures/player_jump.xpm", &img_width, &img_height);
	env->img_enemy_down = mlx_xpm_file_to_image(env->mlx,
			"textures/enemy_down.xpm", &img_width, &img_height);
	env->img_enemy_left = mlx_xpm_file_to_image(env->mlx,
			"textures/enemy_left.xpm", &img_width, &img_height);
	env->img_enemy_right = mlx_xpm_file_to_image(env->mlx,
			"textures/enemy_right.xpm", &img_width, &img_height);
	env->img_enemy_up = mlx_xpm_file_to_image(env->mlx, "textures/enemy_up.xpm",
			&img_width, &img_height);
}

void	print_image(t_env *env, void *img, int x, int y)
{
	if (img)
	{
		if (env->jumping > 0 && (img == env->img_player_down
				|| img == env->img_player_right || img == env->img_player_left
				|| img == env->img_player_up))
		{
			mlx_put_image_to_window(env->mlx, env->win, env->img_player_jump, x
				* TILE_SIZE, y * TILE_SIZE);
			env->jumping--;
		}
		else if (env->enemy_moved > 0 && (img == env->img_enemy_down
				|| img == env->img_enemy_right || img == env->img_enemy_left
				|| img == env->img_enemy_up))
		{
			mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
				* TILE_SIZE);
			env->enemy_moved--;
		}
		else
			mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
				* TILE_SIZE);
	}
	print_moves(env);
}

void	print_player(t_env *env, char c, int x, int y)
{
	if (c == 'S' || c == 'P')
		print_image(env, env->img_player_down, x, y);
	else if (c == 'D')
		print_image(env, env->img_player_right, x, y);
	else if (c == 'A')
		print_image(env, env->img_player_left, x, y);
	else if (c == 'W')
		print_image(env, env->img_player_up, x, y);
	else if (c == 'J')
		print_image(env, env->img_player_jump, x, y);
	else if (c == 'U')
		print_image(env, env->img_enemy_up, x, y);
	else if (c == 'I')
		print_image(env, env->img_enemy_down, x, y);
	else if (c == 'O')
		print_image(env, env->img_enemy_left, x, y);
	else if (c == 'L')
		print_image(env, env->img_enemy_right, x, y);
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
				print_image(env, env->img_wall, x, y);
			else if (env->map[y][x] == '0')
				print_image(env, env->img_floor, x, y);
			else if (env->map[y][x] == 'C')
				print_image(env, env->img_collectible, x, y);
			else if (env->map[y][x] == 'E')
				print_image(env, env->img_exit, x, y);
			else
				print_player(env, env->map[y][x], x, y);
		}
	}
	return (0);
}
