/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:46 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 10:40:41 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf/ft_printf.h"
#include "./so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long   map.ber\n");
		return (1);
	}
	start_game(argv[1]);
	return (0);
}
