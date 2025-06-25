/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 01:20:10 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/mlx/mlx.h"
#include "../../so_long.h"

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

void	open_window(t_env *env)
{
	if (!env->mlx)
		finish_game(env);
	env->win = mlx_new_window(env->mlx, env->win_width, env->win_height,
			"./so_long.c");
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
		else
			mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
				* TILE_SIZE);
	}
	print_moves(env);
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
			else if (env->map[y][x] == 'S' || env->map[y][x] == 'P')
				print_image(env, env->img_player_down, x, y);
			else if (env->map[y][x] == 'D')
				print_image(env, env->img_player_right, x, y);
			else if (env->map[y][x] == 'A')
				print_image(env, env->img_player_left, x, y);
			else if (env->map[y][x] == 'W')
				print_image(env, env->img_player_up, x, y);
			else if (env->map[y][x] == 'J')
				print_image(env, env->img_player_jump, x, y);
		}
	}
	return (0);
}
