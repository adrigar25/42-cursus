/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/17 19:12:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	print_image(t_env *env, void *img, int x, int y)
{
	char	*moves_str;

	if (!img)
		return ;
	if (env->enemy_moved > 0 && (img == env->img_e_d || img == env->img_e_r
			|| img == env->img_e_l || img == env->img_e_u))
	{
		mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
			* TILE_SIZE);
		env->enemy_moved--;
	}
	mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, "number of moves:");
	moves_str = ft_itoa(env->moves);
	mlx_string_put(env->mlx, env->win, 130, 10, 0xFFFFFF, moves_str);
	free(moves_str);
}

void	print_player(t_env *env, char c, int x, int y)
{
	if (c == 'S' || c == 'P')
		print_image(env, env->img_p_d, x, y);
	else if (c == 'D')
		print_image(env, env->img_p_r, x, y);
	else if (c == 'A')
		print_image(env, env->img_p_l, x, y);
	else if (c == 'W')
		print_image(env, env->img_p_u, x, y);
	else if (c == 'U')
		print_image(env, env->img_e_u, x, y);
	else if (c == 'I')
		print_image(env, env->img_e_d, x, y);
	else if (c == 'O')
		print_image(env, env->img_e_l, x, y);
	else if (c == 'L')
		print_image(env, env->img_e_r, x, y);
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
