/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/21 16:15:31 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	check_all_ate(t_table *table)
{
	int	i;

	if (table->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		if ((int)table->philos[i].times_ate < table->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}

int	check_philo_dead(t_philo *philo, t_table *table)
{
	long	now;
	long	last_meal_time;
	long	died;

	pthread_mutex_lock(&philo->meal_lock);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	now = get_time_ms();
	died = now - last_meal_time;
	if (died > (long)table->time_to_die)
	{
		pthread_mutex_lock(&table->sim_stop_lock);
		table->sim_stop = 1;
		pthread_mutex_unlock(&table->sim_stop_lock);
		write_status(philo, table, STATUS_DIED);
		return (1);
	}
	return (0);
}

int	monitor_simulation(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	while (1)
	{
		i = 0;
		while (i < table->n_philos)
		{
			if (check_philo_dead(&table->philos[i], table))
				return (0);
			i++;
		}
		if (check_all_ate(table))
			return (1);
		usleep(100);
	}
	return (1);
}

void	*monitor_thread_fn(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	if (!table)
		return (NULL);
	(void)monitor_simulation(table);
	pthread_mutex_lock(&table->sim_stop_lock);
	table->sim_stop = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (NULL);
}
