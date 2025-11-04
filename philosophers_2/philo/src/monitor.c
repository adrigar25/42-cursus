/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/03 23:29:30 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;
	long	last_meal;
	int		full;

	mutex_handle(&philo->philo_lock, MUTEX_LOCK);
	last_meal = philo->last_meal_time;
	full = philo->full;
	mutex_handle(&philo->philo_lock, MUTEX_UNLOCK);
	elapsed = get_time(TIME_US) - last_meal;
	t_to_die = (long)philo->table->time_to_die;
	if (full)
		return (0);
	if (elapsed > t_to_die)
		return (1);
	return (0);
}

void	*monitor_simulation(void *arg)
{
	int		i;
	int		all_full;
	t_table	*table;

	i = 0;
	table = (t_table *)arg;
	if (!table)
		return (NULL);
	while (!all_threads_running(table))
		usleep(200);
	while (!simulation_stopped(table))
	{
		i = -1;
		all_full = (table->must_eat_count != -1);
		while (++i < table->n_philos && !simulation_stopped(table))
		{
			if (philo_died(table->philos + i))
			{
				write_status(&table->philos[i], table, STATUS_DIED);
				set_int(&table->sim_stop_lock, &table->sim_stop, 1);
			}
			if (all_full && !get_long(&table->philos[i].philo_lock,
					&table->philos[i].full))
				all_full = 0;
		}
		if (all_full && table->must_eat_count != -1)
			set_int(&table->sim_stop_lock, &table->sim_stop, 1);
		ft_usleep(10, table);
	}
	return (NULL);
}
