/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/30 12:26:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_collectibles(t_env *env)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	if (!env->map)
		return (0);
	while (env->map[i])
	{
		j = 0;
		while (env->map[i][j])
		{
			if (env->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	env->collectibles = count;
	return (count);
}

int	close_program(t_env *env)
{
	finish_game(env, 0);
	return (0);
}
