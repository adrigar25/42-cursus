/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:36:48 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/25 16:00:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/ft_printf/ft_printf.h"
#include "./libs/gnl/get_next_line.h"
#include "./libs/libft/libft.h"
#include "./so_long.h"
#include <fcntl.h>

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

int	find_exit(char **map, int x, int y, int rows, int cols, int **visited)
{
	if (x < 0 || y < 0 || x >= cols || y >= rows)
		return (0);
	if (visited[y][x])
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	visited[y][x] = 1;
	if (find_exit(map, x + 1, y, rows, cols, visited))
		return (1);
	if (find_exit(map, x - 1, y, rows, cols, visited))
		return (1);
	if (find_exit(map, x, y + 1, rows, cols, visited))
		return (1);
	if (find_exit(map, x, y - 1, rows, cols, visited))
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

int	check_if_playable(char **map, int rows, int cols)
{
	int	**visited;
	int	j;
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (x < cols && map[y][x] == 'P')
			break ;
		y++;
	}
	if (y == rows)
		return (handle_error(2));
	visited = malloc(sizeof(int *) * rows);
	if (!visited)
		return (handle_error(3));
	i = 0;
	while (i < rows)
	{
		visited[i] = ft_calloc(cols, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (handle_error(3));
		}
		i++;
	}
	i = find_exit(map, x, y, rows, cols, visited);
	j = 0;
	while (j < rows)
	{
		free(visited[j]);
		j++;
	}
	free(visited);
	if (!i)
		return (handle_error(2));
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

int	get_map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	if (!map)
		return (0);
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
	col_count = get_map_width(map);
	if (row_count * col_count < 15)
		return (handle_error(2));
	return (1);
}

int	check_map_elements(char **map)
{
	int	p;
	int	e;
	int	c;
	int	j;
	int	i;

	p = 0;
	e = 0;
	c = 0;
	j = 0;
	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
		}
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (handle_error(2));
	return (1);
}

int	check_wall(char *row, int in_middle)
{
	int	i;
	int	len;

	len = ft_strlen(row);
	if (in_middle)
	{
		if (row[0] != '1' || row[len - 1] != '1')
			return (handle_error(2));
	}
	else
	{
		i = 0;
		while (row[i])
		{
			if (row[i] != '1')
				return (handle_error(2));
			i++;
		}
	}
	return (1);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	if (!check_min_size(map) || !check_rectangular(map))
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		if ((i == 0 || !map[i + 1]) && !check_wall(map[i], 0))
			return (0);
		else if (!check_wall(map[i], 1))
			return (0);
		while (map[i][j])
		{
			if (!ft_strchr("01CEP", map[i][j]))
				return (handle_error(2));
			j++;
		}
		i++;
	}
	if (!check_map_elements(map) || !check_if_playable(map, i, j))
		return (0);
	return (1);
}

char	**open_map(char *map_file)
{
	char	**map;
	int		i;
	int		row_count;
	char	*line;
	int		map_fd;
	int		len;

	if (!check_map_file(map_file))
		return (NULL);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	row_count = 0;
	while ((line = get_next_line(map_fd)))
	{
		free(line);
		row_count++;
	}
	close(map_fd);
	map = malloc(sizeof(char *) * (row_count + 1));
	if (!map)
		return (NULL);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < row_count)
	{
		line = get_next_line(map_fd);
		if (!line)
		{
			free_map(map);
			close(map_fd);
			return (NULL);
		}
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			map[i] = ft_substr(line, 0, len - 1);
		else
			map[i] = ft_substr(line, 0, len);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(map_fd);
	return (map);
}
