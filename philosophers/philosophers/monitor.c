/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:30:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/02 20:30:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	check_all_ate(t_table *table)
{
	int	i;
	int	count;

	if (table->must_eat_count <= 0)
		return (0);
	i = 0;
	count = 0;
	while (i < table->n_philos)
	{
		if ((int)table->philos[i]->times_ate >= table->must_eat_count)
			count++;
		i++;
	}
	return (count == table->n_philos);
}

int	check_philo_dead(t_philo *philo, t_table *table)
{
	long	now;
	int		should_die;

	pthread_mutex_lock(&philo->meal_mutex);
	now = get_time_ms();
	should_die = ((now - philo->last_meal) >= table->time_to_die);
	pthread_mutex_unlock(&philo->meal_mutex);
	if (should_die)
	{
		pthread_mutex_lock(&table->sim_stop_lock);
		if (!table->sim_stop)
			table->sim_stop = 1;
		pthread_mutex_unlock(&table->sim_stop_lock);
		pthread_mutex_lock(&table->write_lock);
		printf("%ld %d %s\n", get_timestamp(table->start_time), philo->id,
			STATUS_DIED);
		pthread_mutex_unlock(&table->write_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	if (!table)
		return (NULL);
	while (1)
	{
		i = 0;
		while (i < table->n_philos)
		{
			if (check_philo_dead(table->philos[i], table))
				return (NULL);
			i++;
		}
		if (check_all_ate(table))
		{
			pthread_mutex_lock(&table->sim_stop_lock);
			table->sim_stop = 1;
			pthread_mutex_unlock(&table->sim_stop_lock);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
