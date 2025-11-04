/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:19:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/03 23:29:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5)
	{
		printf("./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>\n");
		return (1);
	}
	if (!check_args(argc, argv))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	table = init_data(argc, argv);
	if (!table)
		return (1);
	start_simulation(table);
	cleanup_table(table);
	return (0);
}
