/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:36:48 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 22:19:35 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
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
	if (!map || !ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
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
