/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 20:49:35 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	pseudo_random(int max)
{
	static int	seed = 12345;

	seed = (seed * 17 + 42) % 100000;
	return (seed % max);
}

void	randomize_enemies(t_env *env, int width, int height)
{
	int	placed;
	int	try;
	int	x;
	int	y;

	placed = 0;
	try = 0;
	while (placed < env->n_enemies && try++ < width * height * 10)
	{
		x = pseudo_random(width);
		y = pseudo_random(height);
		if (env->map[y][x] != '0')
			continue ;
		if (y > 0 && y < height - 1 && env->map[y - 1][x] != '0' && env->map[y
			+ 1][x] != '0')
			env->map[y][x] = 'O';
		else if (x > 0 && x < width - 1 && env->map[y][x - 1] != '0'
			&& env->map[y][x + 1] != '0')
			env->map[y][x] = 'U';
		else if (placed % 2 == 0)
			env->map[y][x] = 'U';
		else
			env->map[y][x] = 'O';
		placed++;
	}
}

int	move_enemies(t_env *env)
{
	if (env->enemy_moved != 0)
		return (0);
	if (handle_top_half(env) || handle_bottom_half(env))
		return (0);
	env->enemy_moved = 500;
	return (0);
}
