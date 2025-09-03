/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:53:55 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/02 18:48:08 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include <stdio.h>
#include <unistd.h>

// static void	set_sim_stop_flag(t_table *table, int state)
// {
// 	pthread_mutex_lock(&table->sim_stop_lock);
// 	table->sim_stop = state;
// 	pthread_mutex_unlock(&table->sim_stop_lock);
// }

// static int	kill_philo(t_philo *philo)
// {
// 	time_t	time;

// 	time = get_time_ms();
// 	if ((time - philo->last_meal) >= philo->table->time_to_die)
// 	{
// 		set_sim_stop_flag(philo->table, 1);
// 		write_status(philo, STATUS_DIED);
// 		pthread_mutex_unlock(&philo->meal_time_lock);
// 		return (1);
// 	}
// 	return (0);
// }

int	has_simulation_stopped(t_table *table)
{
	int	r;

	r = 0;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop == 1)
		r = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (r);
}

void	philo_sleep(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_ms() + sleep_time;
	while (get_time_ms() < wake_up)
	{
		if (has_simulation_stopped(table))
			break ;
		usleep(100);
	}
}

void	*one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	write_status(philo, STATUS_FORK);
	philo_sleep(philo->table, philo->table->time_to_die);
	write_status(philo, STATUS_DIED);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
	return (NULL);
}

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	write_status(philo, STATUS_FORK);
	pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
	write_status(philo, STATUS_FORK);
	write_status(philo, STATUS_EATING);
	philo->last_meal = get_time_ms();
	philo_sleep(philo->table, philo->table->time_to_eat);
	if(!has_simulation_stopped(philo->table))
		philo->times_ate += 1;
	pthread_mutex_unlock(&philo->meal_time_lock);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
}

static void	think_routine(t_philo *philo, int silent)
{
	int	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = ((philo->table->time_to_die - (get_time_ms()) - philo->last_meal) - philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && !silent)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (!silent)
		write_status(philo, STATUS_THINKING);
	philo_sleep(philo->table, time_to_think);
}

void	*philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_lock);
	while (!has_simulation_stopped(philo->table))
	{
		eat_sleep_routine(philo);
		think_routine(philo, 0);
	}
	pthread_mutex_unlock(&philo->meal_time_lock);
	return (NULL);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	printf("Philosopher %d starting routine\n", philo->id);
	if (philo->table->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (philo->table->n_philos == 1)
	{
		one_philo_routine(philo);
		return (NULL);
	}

	if (philo->table->n_philos > 1 && philo->id % 2)
		usleep(2000);
		
		philo_routine(philo);
	return (NULL);
}

int	init_simulation(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = get_time_ms();

	for (i = 0; i < table->n_philos; i++) {
    if (!table->philos[i]) {
        fprintf(stderr, "Philosopher %d is NULL\n", i);
        return 0;
    }
    if (pthread_create(&table->philos[i]->thread, NULL, philo, table->philos[i])) {
        fprintf(stderr, "Error creating thread %d\n", i);
        return 0;
    }
	}
	// if (table->n_philos > 1)
	// {
	// 	if (!pthread_create(&table->monitor_thread, NULL, monitor_routine,
	// 			table))
	// 		return (0);
	// }
	for (i = 0; i < table->n_philos; i++) {
    if (table->philos[i])
        pthread_join(table->philos[i]->thread, NULL);
	}
	return (1);
}
