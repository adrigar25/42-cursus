/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 00:00:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_player_position(t_env *env)
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
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	move_player_to(t_env *env, int new_x, int new_y, char key)
{
	int	img_width;
	int	img_height;

	if (env->map[new_y][new_x] != '1')
	{
		env->map[env->player_y][env->player_x] = '0';
		if (env->map[new_y][new_x] == 'C' && env->collectibles--)
			env->jumping = 10;
		if (!env->collectibles)
			env->img_exit = mlx_xpm_file_to_image(env->mlx,
					"textures/exit_2.xpm", &img_width, &img_height);
		if (!env->collectibles && env->map[new_y][new_x] == 'E')
			finish_game(env);
		env->player_x = new_x;
		env->player_y = new_y;
		env->moves++;
	}
	env->map[env->player_y][env->player_x] = key;
}
