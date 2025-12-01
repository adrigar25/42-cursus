/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 02:47:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	simulation_stopped(t_table *table)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop == 1)
		ret = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (ret);
}

int	philo_died(t_philo *philo)
{
	long	last_meal;
	int		full;

	pthread_mutex_lock(&philo->philo_lock);
	last_meal = philo->last_meal_time;
	full = philo->full;
	pthread_mutex_unlock(&philo->philo_lock);
	if (full)
		return (0);
	if ((get_time(TIME_MS) - last_meal) > (long)philo->table->time_to_die)
	{
		write_status(philo, philo->table, STATUS_DIED);
		set_int(&philo->table->sim_stop_lock, &philo->table->sim_stop, 1);
		return (1);
	}
	return (0);
}

static int	all_philos_have_eaten(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		if (!get_long(&table->philos[i].philo_lock, &table->philos[i].full))
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_simulation(void *arg)
{
	int		i;
	t_table	*table;

	i = 0;
	table = (t_table *)arg;
	if (!table)
		return (NULL);
	wait_all_threads_running(table);
	while (!simulation_stopped(table))
	{
		i = 0;
		while (i < table->n_philos && !simulation_stopped(table)
			&& !philo_died(table->philos + i))
			i++;
		if (!simulation_stopped(table) && table->must_eat_count != -1
			&& all_philos_have_eaten(table))
			set_int(&table->sim_stop_lock, &table->sim_stop, 1);
		ft_usleep(50, table);
	}
	return (NULL);
}
