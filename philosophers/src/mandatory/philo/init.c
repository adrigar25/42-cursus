/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:12:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/02 21:12:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_philosophers(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	table->philos = malloc(sizeof(t_philo *) * table->n_philos);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->id = i + 1;
		table->philos[i]->times_ate = 0;
		table->philos[i]->fork[0] = i;
		table->philos[i]->fork[1] = (i + 1) % table->n_philos;
		if (i % 2)
		{
			table->philos[i]->fork[0] = (i + 1) % table->n_philos;
			table->philos[i]->fork[1] = i;
		}
		table->philos[i]->table = table;
		table->philos[i]->last_meal = -1;
		pthread_mutex_init(&table->philos[i]->meal_time_lock, NULL);
		i++;
	}
	return (1);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!table)
		return (0);
	table->n_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	if (table->n_philos < 1 || table->time_to_die < 0 || table->time_to_eat < 0
		|| table->time_to_sleep < 0 || (argc == 6 && table->must_eat_count < 0))
		return (0);
	table->sim_stop = 0;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->sim_stop_lock, NULL);
	if (!init_philosophers(table) || !init_forks(table))
		return (0);
	return (1);
}
