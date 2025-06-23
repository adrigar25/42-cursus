#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include "./so_long.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long   map.ber\n");
		return (1);
	}

	if (!check_map_file(argv[1]))
		return (1);

	start_game(argv[1]);

	return (0);
}