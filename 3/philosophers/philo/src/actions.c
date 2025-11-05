/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 01:10:00 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	get_forks(t_philo *philo)
{
	if (!philo)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		write_status(philo, philo->table, STATUS_FORK);
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		write_status(philo, philo->table, STATUS_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		write_status(philo, philo->table, STATUS_FORK);
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		write_status(philo, philo->table, STATUS_FORK);
	}
	return (1);
}

int	eat(t_philo *philo)
{
	if (!philo || simulation_stopped(philo->table))
		return (0);
	get_forks(philo);
	if (simulation_stopped(philo->table))
	{
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		return (0);
	}
	set_long(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_MS));
	write_status(philo, philo->table, STATUS_EAT);
	increment_int(&philo->philo_lock, &philo->times_ate);
	if (philo->table->must_eat_count != -1)
		set_long(&philo->philo_lock, &philo->full, (get_int(&philo->philo_lock,
					&philo->times_ate) >= philo->table->must_eat_count));
	ft_usleep(philo->table->time_to_eat * 1000, philo->table);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	return (1);
}

void	think(t_philo *philo, int print)
{
	long	time_to_think;
	long	time_to_sleep;
	long	time_to_eat;

	if (print)
		write_status(philo, philo->table, STATUS_THINK);
	if (philo->table->n_philos % 2 == 0)
		return ;
	time_to_sleep = (long)philo->table->time_to_sleep;
	time_to_eat = (long)philo->table->time_to_eat;
	time_to_think = time_to_eat * 2 - time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	ft_usleep(time_to_think * 1000, philo->table);
}

int	sleep_philo(int time_to_sleep, t_table *table)
{
	if (!table)
		return (0);
	ft_usleep(time_to_sleep * 1000, table);
	return (1);
}
