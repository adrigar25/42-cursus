#include "./ft_printf/ft_printf.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>

int	check_map(char **map)
{
	int	i;
	int	j;
	int	row_count;

	row_count = 0;
	while (map[row_count])
		row_count++;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return ((0));
		j++;
	}
	i = 1;
	while (i < row_count - 2)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				ft_printf("n");
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			j++;
		}
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
    i++;
	while (map[i][j])
	{
		ft_printf("%c", (map[i][j] == '\n' ? '\\' : map[i][j]));
		if (map[i][j] == '\n')
			ft_printf("n");
		if (map[i][j] != '1')
			return ((0));
		j++;
	}
	return (1);
}

char	**open_map(char *map_file)
{
	char	**map;
	int		i;
	int		row_count;
	int		col_count;
	char	*line;
	int		map_fd;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(map_fd);
	if (!line)
		return (NULL);
	row_count = 1;
	col_count = ft_strlen(line);
	while (line)
	{
		if ((int)ft_strlen(line) != col_count)
		{
			free(line);
			close(map_fd);
			return (NULL);
		}
		free(line);
		line = get_next_line(map_fd);
		if (line)
			row_count++;
	}
	close(map_fd);
	if (col_count * row_count < 15)
	{
		ft_printf("Map is too small. Exiting.\n");
		return (NULL);
	}
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
		map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			close(map_fd);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(map_fd);
	return (map);
}
