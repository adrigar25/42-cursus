/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 01:46:15 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

t_table	*init_data(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (!init_table(table, argc, argv))
	{
		free(table);
		return (NULL);
	}
	if (init_forks(table) || init_philos(table))
	{
		cleanup_table(table);
		return (NULL);
	}
	return (table);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!table || argc < 5)
		return (0);
	table->n_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	if (table->n_philos <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (0);
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->sim_stop_lock, NULL);
	pthread_mutex_init(&table->table_lock, NULL);
	table->sim_stop = 0;
	table->all_threads_created = 0;
	table->threads_running = 0;
	return (1);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->n_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	return (0);
}

int	init_philos(t_table *table)
{
	int	n_philos;
	int	i;

	if (!table)
		return (1);
	n_philos = table->n_philos;
	table->philos = malloc(sizeof(t_philo) * n_philos);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < n_philos)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].times_ate = 0;
		table->philos[i].full = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % n_philos;
		pthread_mutex_init(&table->philos[i].philo_lock, NULL);
		i++;
	}
	return (0);
}
