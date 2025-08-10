/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:53:55 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/10 14:24:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	is_dead(t_philo *philo)
{
	long	time_since_last_meal;

	time_since_last_meal = get_timestamp(philo->data) - philo->last_meal;
	if (time_since_last_meal >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		if (!philo->data->someone_died)
		{
			philo->data->someone_died = 1;
			printf("%ld %d died\n", get_timestamp(philo->data), philo->id);
		}
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (1);
	}
	return (0);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->someone_died)
		printf("%ld %d %s\n", get_timestamp(philo->data), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_forks(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
	}
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void	smart_sleep(long duration_ms, t_philo *philo)
{
	long	start;

	start = get_timestamp(philo->data);
	while ((get_timestamp(philo->data) - start) < duration_ms)
	{
		if (is_dead(philo))
			break ;
		usleep(100);
	}
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo);
}

void	philo_eat(t_philo *philo)
{
	print_status(philo, "is eating");
	smart_sleep(philo->data->time_to_eat, philo);
	philo->last_meal = get_timestamp(philo->data);
	philo->meals_eaten++;
}

void	philo_think(t_philo *philo)
{
	long	think_time;

	think_time = (philo->data->time_to_die - philo->data->time_to_eat
			- philo->data->time_to_sleep) / 2;
	if (think_time < 0)
		think_time = 0;
	print_status(philo, "is thinking");
	smart_sleep(think_time, philo);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		smart_sleep(philo->data->time_to_eat / 2, philo);
	while (!philo->data->someone_died && (philo->data->must_eat == -1
			|| philo->meals_eaten < philo->data->must_eat))
	{
		if (is_dead(philo))
			break ;
		philo_think(philo);
		take_forks(philo);
		philo_eat(philo);
		put_forks(philo);
		philo_sleep(philo);
	}
	return (NULL);
}