/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 14:16:47 by agarcia          ###   ########.fr       */
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
	while (placed < env->n_enemies && try < width * height * 10)
	{
		x = pseudo_random(width);
		y = pseudo_random(height);
		if (env->map[y][x] == '0')
		{
			// Si arriba y abajo no son suelo, cambia a 'O'
			if (y > 0 && env->map[y - 1][x] != '0' && y < height - 1 && env->map[y + 1][x] != '0')
				env->map[y][x] = 'O';
			// Si a la izquierda y derecha no son suelo, cambia a 'U'
			else if (x > 0 && env->map[y][x - 1] != '0' && x < width - 1 && env->map[y][x + 1] != '0')
				env->map[y][x] = 'U';
			else if (placed % 2 == 0)
				env->map[y][x] = 'U';
			else
				env->map[y][x] = 'O';
			placed++;
		}
		try++;
	}
}

int	move_enemies(t_env *env)
{
	const char	*player_chars = "PWSDJ";
	int			x;
	int			y;

	if (env->enemy_moved != 0)
		return (0);
	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			if (env->map[y][x] == 'U')
			{
				if (y > 0 && strchr(player_chars, env->map[y - 1][x]))
				{
					finish_game(env);
					return (0);
				}
				if (y > 0 && env->map[y - 1][x] == '0')
				{
					env->map[y - 1][x] = 'U';
					env->map[y][x] = '0';
				}
				else
					env->map[y][x] = 'I';
			}
			else if (env->map[y][x] == 'O')
			{
				if (x > 0 && strchr(player_chars, env->map[y][x - 1]))
				{
					finish_game(env);
					return (0);
				}
				if (x > 0 && env->map[y][x - 1] == '0')
				{
					env->map[y][x - 1] = 'O';
					env->map[y][x] = '0';
				}
				else
					env->map[y][x] = 'L';
			}
			x++;
		}
		y++;
	}
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
			if (env->map[y][x] == 'I')
			{
				if (env->map[y + 1] && strchr(player_chars, env->map[y + 1][x]))
				{
					finish_game(env);
					return (0);
				}
				if (env->map[y + 1] && env->map[y + 1][x] == '0')
				{
					env->map[y + 1][x] = 'I';
					env->map[y][x] = '0';
				}
				else
					env->map[y][x] = 'U';
			}
			else if (env->map[y][x] == 'L')
			{
				if (env->map[y][x + 1] && strchr(player_chars, env->map[y][x
						+ 1]))
				{
					finish_game(env);
					return (0);
				}
				if (env->map[y][x + 1] && env->map[y][x + 1] == '0')
				{
					env->map[y][x + 1] = 'L';
					env->map[y][x] = '0';
				}
				else
					env->map[y][x] = 'O';
			}
			x--;
		}
		y--;
	}
	env->enemy_moved = 50;
	return (0);
}
