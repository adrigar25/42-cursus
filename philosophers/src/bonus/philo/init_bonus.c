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

#include "philo_bonus.h"
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

int	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo *) * table->n_philos);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->id = i + 1;
		table->philos[i]->times_ate = 0;
		table->philos[i]->table = table;
		table->philos[i]->last_meal = 0;
		pthread_mutex_init(&table->philos[i]->meal_time_lock, NULL);
		i++;
	}
	return (1);
}

int	init_semaphores(t_table *table)
{
	sem_unlink("/forks_sem");
	sem_unlink("/write_sem");
	table->forks = sem_open("/forks_sem", O_CREAT, 0644, table->n_philos);
	table->write_sem = sem_open("/write_sem", O_CREAT, 0644, 1);
	if (table->forks == SEM_FAILED || table->write_sem == SEM_FAILED)
		return (0);
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
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
	if (!init_philosophers(table) || !init_semaphores(table))
		return (0);
	table->sim_stop = 0;
	return (1);
}
