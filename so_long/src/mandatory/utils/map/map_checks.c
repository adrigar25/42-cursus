/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:18:17 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 03:28:01 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_map_file(char *map_file)
{
	if (!ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
	{
		ft_printf("Error: the file must have a .ber extension\n");
		return (0);
	}
	return (1);
}

int	check_if_playable(t_env *env)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(int *) * get_map_height(env->map));
	if (!visited)
		return (handle_error(3));
	i = -1;
	while (env->map[++i])
	{
		visited[i] = ft_calloc(ft_strlen(env->map[0]), sizeof(char));
		if (!visited[i])
		{
			free_map(visited);
			return (handle_error(3));
		}
	}
	if (!find_exit(env->map, env->player_x, env->player_y, visited))
	{
		free_map(visited);
		return (handle_error(2));
	}
	return (1);
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

int	check_wall(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	i = -1;
	while (map[++i])
	{
		j = -1;
		if ((i == 0 || !map[i + 1]))
		{
			while (map[i][++j])
				if (map[i][j] != '1')
					return (0);
			j = -1;
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		while (map[i][++j])
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
	}
	return (1);
}

int	check_map(t_env *env)
{
	return (get_player_position(env) && count_collectibles(env)
		&& check_rectangular(env->map) && check_wall(env->map)
		&& check_if_playable(env));
}
