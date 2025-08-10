/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:34:02 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/03 20:27:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	handle_enemy_horizontal(t_env *env, int x, int y, int dir)
{
	int	new_x;

	new_x = x + dir;
	if (env->map[y][new_x] && ft_strchr("PWASDJ", env->map[y][new_x]))
		return (finish_game(env, 0), 1);
	if (env->map[y][new_x] && env->map[y][new_x] == '0')
	{
		if (dir == -1)
			env->map[y][new_x] = 'O';
		else
			env->map[y][new_x] = 'L';
		env->map[y][x] = '0';
	}
	else
	{
		if (dir == -1)
			env->map[y][x] = 'L';
		else
			env->map[y][x] = 'O';
	}
	return (0);
}

int	handle_enemy_vertical(t_env *env, int x, int y, int dir)
{
	int	new_y;

	new_y = y + dir;
	if (env->map[new_y] && ft_strchr("PWASDJ", env->map[new_y][x]))
		return (finish_game(env, 0), 1);
	if (env->map[new_y] && env->map[new_y][x] == '0')
	{
		if (dir == -1)
			env->map[new_y][x] = 'U';
		else
			env->map[new_y][x] = 'I';
		env->map[y][x] = '0';
	}
	else
	{
		if (dir == -1)
			env->map[y][x] = 'I';
		else
			env->map[y][x] = 'U';
	}
	return (0);
}

int	handle_top_half(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			if (env->map[y][x] == 'U' && handle_enemy_vertical(env, x, y, -1))
				return (1);
			else if (env->map[y][x] == 'O' && handle_enemy_horizontal(env, x, y,
					-1))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	handle_bottom_half(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (env->map[y])
		y++;
	y--;
	while (y >= 0)
	{
		x = 0;
		while (env->map[y][x])
			x++;
		x--;
		while (x >= 0)
		{
			if (env->map[y][x] == 'I' && handle_enemy_vertical(env, x, y, 1))
				return (1);
			else if (env->map[y][x] == 'L' && handle_enemy_horizontal(env, x, y,
					1))
				return (1);
			x--;
		}
		y--;
	}
	return (0);
}
