/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:18:17 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/03 18:21:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**ft_strdup_matrix(char **matrix)
{
	char	**dup;
	int		i;
	int		j;

	if (!matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (matrix[++i])
	{
		dup[i] = ft_strdup(matrix[i]);
		if (!dup[i])
		{
			j = -1;
			while (++j < i)
				free(dup[j]);
			return (free(dup), NULL);
		}
	}
	return (dup[i] = NULL, dup);
}

int	check_if_playable(char **map, int x, int y)
{
	char	**aux;
	int		r;

	aux = ft_strdup_matrix(map);
	if (!aux)
		return (0);
	r = 0;
	if (aux[y][x] == '1' || aux[y][x] == 'V')
		r = 0;
	else if (aux[y][x] == 'E')
		r = 1;
	else
	{
		aux[y][x] = 'V';
		if (aux[y][x + 1])
			r = check_if_playable(aux, x + 1, y);
		if (!r && x > 0)
			r = check_if_playable(aux, x - 1, y);
		if (!r && aux[y + 1])
			r = check_if_playable(aux, x, y + 1);
		if (!r && y > 0)
			r = check_if_playable(aux, x, y - 1);
	}
	free_map(aux);
	return (r);
}

int	check_rectangular(char **map)
{
	int	len;
	int	i;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_format(char **map)
{
	int	width;
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		if (i == 0 || !map[i + 1])
		{
			while (++j < width)
				if (map[i][j] != '1')
					return (0);
		}
		else if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		j = -1;
		while (++j < width)
			if (!ft_strchr("10CPE", map[i][j]))
				return (0);
	}
	return (1);
}

int	check_map(t_env *env)
{
	return (get_player_position(env) && count_collectibles(env)
		&& check_rectangular(env->map) && check_format(env->map)
		&& check_if_playable(env->map, env->player_x, env->player_y));
}
