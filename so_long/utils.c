#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>

int check_map_file(char *map_file)
{
    if (!ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
	{
		ft_printf("Error: the file must have a .ber extension\n");
		return (0);
	}
    return (1);
}