/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:36:48 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 02:45:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	count_map_lines(char *map_file)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

char	**open_map(char *map_file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int		len;

	i = 0;
	map = malloc(sizeof(char *) * (count_map_lines(map_file) + 1));
	if (!map)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			map[i++] = ft_substr(line, 0, len - 1);
		else if (len > 0)
			map[i++] = ft_substr(line, 0, len);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
