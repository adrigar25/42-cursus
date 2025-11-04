/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/12 15:43:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
				if (env->player_x || env->player_y)
					return (0);
				env->player_x = x;
				env->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (env->player_x && env->player_y)
		return (1);
	return (0);
}

void	move_player_to(t_env *env, int new_x, int new_y, char key)
{
	int	i_w;
	int	i_h;

	i_h = TILE_SIZE;
	i_w = TILE_SIZE;
	if (env->map[new_y][new_x] == '1')
		return ;
	if (env->map[new_y][new_x] == 'E' && env->collectibles != 0)
		return ;
	if (env->map[new_y][new_x] == 'E' && env->collectibles == 0)
		finish_game(env, 0);
	if (env->map[new_y][new_x] == 'I' || env->map[new_y][new_x] == 'O'
		|| env->map[new_y][new_x] == 'P' || env->map[new_y][new_x] == 'U')
		finish_game(env, 0);
	env->map[env->player_y][env->player_x] = '0';
	if (env->map[new_y][new_x] == 'C' && env->collectibles--)
		env->jumping = 10;
	if (env->collectibles == 0)
		env->img_exit = load_texture(env->mlx, "exit_2", &i_w, &i_h);
	env->player_x = new_x;
	env->player_y = new_y;
	env->moves++;
	env->map[env->player_y][env->player_x] = key;
	ft_printf("Movimientos: %d\n", env->moves);
}
