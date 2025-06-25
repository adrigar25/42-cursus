/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:36:48 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 01:34:15 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	find_exit(char **map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || !map[y][x])
		return (0);
	if (visited[y][x] || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	visited[y][x] = '1';
	if (find_exit(map, x + 1, y, visited) || find_exit(map, x - 1, y, visited)
		|| find_exit(map, x, y + 1, visited) || find_exit(map, x, y - 1,
			visited))
		return (1);
	return (0);
}

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
		return (handle_error(2));
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (handle_error(2));
		i++;
	}
	return (1);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	check_min_size(char **map)
{
	int	row_count;
	int	col_count;

	if (!map || !map[0])
		return (handle_error(2));
	row_count = get_map_height(map);
	col_count = ft_strlen(map[0]);
	if (row_count * col_count < 15)
		return (handle_error(2));
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
	if (!get_player_position(env) || !count_collectibles(env)
		|| !check_min_size(env->map) || !check_rectangular(env->map)
		|| !check_wall(env->map) || !check_if_playable(env))
		return (0);
	return (1);
}

char	**open_map(char *map_file)
{
	char	**map;
	int		i;
	char	*line;
	int		map_fd;
	int		len;

	i = 0;
	if (!check_map_file(map_file))
		return (NULL);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	while (get_next_line(map_fd))
		i++;
	close(map_fd);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	map_fd = open(map_file, O_RDONLY);
	line = get_next_line(map_fd);
	i = 0;
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			map[i] = ft_substr(line, 0, len - 1);
		else
			map[i] = ft_substr(line, 0, len);
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	map[i] = NULL;
	close(map_fd);
	return (map);
}
