/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:53:55 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/29 15:26:52 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	solo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);

	printf("Philosopher %d is eating\n", philo->id);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
	printf("Philosopher %d is sleeping\n", philo->id);
	usleep(philo->table->time_to_sleep * 1000);
	printf("Philosopher %d is thinking\n", philo->id);
	return (NULL);
}