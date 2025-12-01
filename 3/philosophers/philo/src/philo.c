/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:18:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 01:48:00 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	write_status(t_philo *philo, t_table *table, const char *status)
{
	static int	died_flag = 0;

	if (died_flag)
		return (0);
	pthread_mutex_lock(&table->write_lock);
	if (died_flag)
	{
		pthread_mutex_unlock(&table->write_lock);
		return (0);
	}
	if (!ft_strcmp(status, STATUS_DIED))
		died_flag = 1;
	printf("%ld %u %s\n", get_timestamp(table->start_time), philo->id, status);
	pthread_mutex_unlock(&table->write_lock);
	return (1);
}

void	*solo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_long(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_MS));
	increment_int(&philo->table->table_lock, &philo->table->threads_running);
	write_status(philo, philo->table, STATUS_FORK);
	while (!simulation_stopped(philo->table))
		usleep(1000);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	table = philo->table;
	if (!table)
		return (NULL);
	increment_int(&table->table_lock, &table->threads_running);
	set_long(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_MS));
	wait_all_threads_created(table);
	desync_philos(philo);
	while (!simulation_stopped(table))
	{
		if (get_long(&philo->philo_lock, &philo->full))
			break ;
		eat(philo);
		write_status(philo, table, STATUS_SLEEP);
		ft_usleep(table->time_to_sleep * 1000, table);
		think(philo, 1);
	}
	return (NULL);
}

int	start_simulation(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	set_long(&table->table_lock, &table->start_time, get_time(TIME_MS));
	if (table->n_philos == 1)
		pthread_create(&table->philos[0].thread, NULL, solo_routine,
			(void *)&table->philos[0]);
	else
		create_threads(table);
	set_int(&table->table_lock, &table->all_threads_created, 1);
	pthread_create(&table->monitor_thread, NULL, monitor_simulation, table);
	pthread_join(table->monitor_thread, NULL);
	set_int(&table->sim_stop_lock, &table->sim_stop, 1);
	i = 0;
	while (i < table->n_philos)
		pthread_join(table->philos[i++].thread, NULL);
	return (1);
}
