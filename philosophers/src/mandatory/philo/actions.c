/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:40:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/05 19:20:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	write_status(t_philo *philo, const char *status)
{
	t_table	*table;
	long	ts;
	int		id;

	if (!philo || !status)
		return (0);
	table = philo->table;
	pthread_mutex_lock(&table->write_lock);
	if (!table->sim_stop)
	{
		ts = get_timestamp(table->start_time);
		id = (int)philo->id;
		printf("%ld %d %s\n", ts, id, status);
	}
	pthread_mutex_unlock(&table->write_lock);
	return (1);
}

void	sleep_philo(long duration_ms, t_table *table, int check_stop)
{
	long	start;

	start = get_time_ms();
	if (check_stop)
	{
		while (!table->sim_stop)
		{
			if (get_time_ms() - start >= duration_ms)
				break ;
			usleep(100);
		}
	}
	else
		while (get_time_ms() - start < duration_ms)
			usleep(500);
}

long	calc_think_time(t_philo *philo)
{
	t_table	*table;
	long	time_left;
	long	time_to_think;

	table = philo->table;
	pthread_mutex_lock(&philo->meal_time_lock);
	time_left = table->time_to_die - (get_time_ms() - philo->last_meal);
	pthread_mutex_unlock(&philo->meal_time_lock);
	time_to_think = (time_left - table->time_to_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > table->time_to_sleep)
		time_to_think = table->time_to_sleep / 2;
	return (time_to_think);
}

int	eat(t_philo *philo)
{
	t_table	*table;
	int		first_fork;
	int		second_fork;

	if (!philo)
		return (0);
	table = philo->table;
	if (philo->fork[0] < philo->fork[1])
	{
		first_fork = philo->fork[0];
		second_fork = philo->fork[1];
	}
	else
	{
		first_fork = philo->fork[1];
		second_fork = philo->fork[0];
	}
	pthread_mutex_lock(&table->forks[first_fork]);
	write_status(philo, STATUS_FORK);
	pthread_mutex_lock(&table->forks[second_fork]);
	write_status(philo, STATUS_FORK);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	write_status(philo, STATUS_EATING);
	sleep_philo(table->time_to_eat, table, 1);
	pthread_mutex_lock(&table->sim_stop_lock);
	if (!table->sim_stop)
		philo->times_ate++;
	pthread_mutex_unlock(&table->sim_stop_lock);
	pthread_mutex_unlock(&table->forks[second_fork]);
	pthread_mutex_unlock(&table->forks[first_fork]);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	long	time_to_think;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->table->n_philos == 1)
	{
		write_status(philo, STATUS_FORK);
		sleep_philo(philo->table->time_to_die, philo->table, 1);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		sleep_philo(philo->table->time_to_eat / 2, philo->table, 0);
	while (!philo->table->sim_stop)
	{
		if (!eat(philo))
			break ;
		if (philo->table->must_eat_count != -1
			&& philo->times_ate >= (unsigned int)philo->table->must_eat_count)
			break ;
		sleep_philo(philo->table->time_to_sleep, philo->table, 1);
		time_to_think = calc_think_time(philo);
		if (time_to_think > 0)
			sleep_philo(time_to_think, philo->table, 1);
		write_status(philo, STATUS_THINKING);
	}
	return (NULL);
}
