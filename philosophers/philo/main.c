/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:26:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/02 17:26:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (*argv[i] < '0' || *argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_arguments(argc, argv))
	{
		printf("Error: Invalid arguments\n");
		printf("Usage: ");
		printf("%s n_philos time_to_die time_to_eat time_to_sleep [must_eat_count]\n",
			argv[0]);
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	init_table(table, argc, argv);
	init_simulation(table);
	return (0);
}
