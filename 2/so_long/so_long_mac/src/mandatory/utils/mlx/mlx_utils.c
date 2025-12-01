/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/04 17:38:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	clear_images(t_env *env)
{
	if (env->img_floor)
		mlx_destroy_image(env->mlx, env->img_floor);
	if (env->img_wall)
		mlx_destroy_image(env->mlx, env->img_wall);
	if (env->img_exit)
		mlx_destroy_image(env->mlx, env->img_exit);
	if (env->img_collectible)
		mlx_destroy_image(env->mlx, env->img_collectible);
	if (env->img_player_down)
		mlx_destroy_image(env->mlx, env->img_player_down);
}

void	init_images(t_env *env)
{
	int	img_w;
	int	img_h;

	if (!env->win)
		finish_game(env, 0);
	img_h = TILE_SIZE;
	img_w = TILE_SIZE;
	env->img_floor = mlx_xpm_file_to_image(env->mlx, "imgs/floor.xpm", &img_w,
			&img_h);
	env->img_wall = mlx_xpm_file_to_image(env->mlx, "imgs/wall.xpm", &img_w,
			&img_h);
	env->img_exit = mlx_xpm_file_to_image(env->mlx, "imgs/exit_2.xpm", &img_w,
			&img_h);
	env->img_collectible = mlx_xpm_file_to_image(env->mlx,
			"imgs/collectible.xpm", &img_w, &img_h);
	env->img_player_down = mlx_xpm_file_to_image(env->mlx,
			"imgs/player_down.xpm", &img_w, &img_h);
}

void	print_image(t_env *env, char img, int x, int y)
{
	if (img == '1')
		mlx_put_image_to_window(env->mlx, env->win, env->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (img == '0')
		mlx_put_image_to_window(env->mlx, env->win, env->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (img == 'C')
		mlx_put_image_to_window(env->mlx, env->win, env->img_collectible, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (img == 'E')
		mlx_put_image_to_window(env->mlx, env->win, env->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (img == 'P')
		mlx_put_image_to_window(env->mlx, env->win, env->img_player_down, x
			* TILE_SIZE, y * TILE_SIZE);
}

int	print_map(t_env *env)
{
	int	x;
	int	y;

	init_images(env);
	y = -1;
	while (env->map[++y])
	{
		x = -1;
		while (env->map[y][++x])
			print_image(env, env->map[y][x], x, y);
	}
	return (0);
}
