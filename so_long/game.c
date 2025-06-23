#include "../mlx/mlx.h"
#include "./so_long.h"
#include "./ft_printf/ft_printf.h"

int	start_game(char *map_file)
{
	char **map;

    if(!check_map_file(map_file))
        return (0);
	map = open_map(map_file);
    if(!check_map(map))
    {
        ft_printf("Error: invalid map\n");
    }

	return (!map);
}