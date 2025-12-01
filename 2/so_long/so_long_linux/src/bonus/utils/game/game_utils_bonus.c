/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 22:11:39 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
