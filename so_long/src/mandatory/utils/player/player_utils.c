/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/31 16:19:12 by agarcia          ###   ########.fr       */
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

void	move_player_to(t_env *env, int new_x, int new_y)
{
	if (env->map[new_y][new_x] == '1')
		return ;
	if (env->map[new_y][new_x] == 'E' && env->collectibles != 0)
		return ;
	if (env->map[new_y][new_x] == 'E' && env->collectibles == 0)
		finish_game(env);
	env->map[env->player_y][env->player_x] = '0';
	if (env->map[new_y][new_x] == 'C')
		env->collectibles--;
	env->player_x = new_x;
	env->player_y = new_y;
	env->moves++;
	env->map[new_y][new_x] = 'P';
	ft_printf("Movimientos: %d\n", env->moves);
}
