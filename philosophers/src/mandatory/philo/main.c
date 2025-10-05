/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:26:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/05 19:16:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, routine,
				table->philos[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&table->monitor_thread, NULL, monitor, table) != 0)
		return (0);
	return (1);
}

int	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_time_ms();
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_lock);
		table->philos[i]->last_meal = table->start_time;
		pthread_mutex_unlock(&table->philos[i]->meal_time_lock);
		i++;
	}
	if (!create_threads(table))
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
	return (1);
}

int	free_table(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i]->meal_time_lock);
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
	free(table->forks);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->sim_stop_lock);
	free(table);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_arguments(argc, argv))
	{
		printf(USAGE_MSG, argv[0]);
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (!init_table(table, argc, argv))
		return (free_table(table));
	if (!start_simulation(table))
		return (free_table(table));
	return (0);
}
