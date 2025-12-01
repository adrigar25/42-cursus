/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/01 14:56:04 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
		mlx_put_image_to_window(env->mlx, env->win, env->img_p_d, x * TILE_SIZE,
			y * TILE_SIZE);
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
			print_image(env, env->map[y][x], x, y);
	}
	return (0);
}
