/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:40:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/02 19:40:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:40:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/03 13:20:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <string.h>

int	write_status(t_philo *philo, const char *status)
{
	long	ts;

	if (!philo || !status)
		return (0);
	sem_wait(philo->table->write_sem);
	if (!philo->table->sim_stop || strcmp(status, STATUS_DIED) == 0)
	{
		ts = get_timestamp(philo->table->start_time);
		printf("%ld %d %s\n", ts, philo->id, status);
		fflush(stdout);
	}
	sem_post(philo->table->write_sem);
	return (1);
}

static void	sleep_philo(long duration_ms)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < duration_ms)
		usleep(500);
}

static void	*philo_monitor(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while (1)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (get_time_ms() - philo->last_meal >= table->time_to_die)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			sem_wait(table->write_sem);
			if (!table->sim_stop)
			{
				printf("%ld %d %s\n", get_timestamp(table->start_time),
					philo->id, STATUS_DIED);
				fflush(stdout);
				table->sim_stop = 1;
			}
			sem_post(table->write_sem);
			for (int i = 0; i < table->n_philos; i++)
				if (table->philos[i]->pid != philo->pid)
					kill(table->philos[i]->pid, SIGKILL);
			exit(1);
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		usleep(500);
	}
	return (NULL);
}

static void	eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	sem_wait(table->forks);
	write_status(philo, STATUS_FORK);
	sem_wait(table->forks);
	write_status(philo, STATUS_FORK);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
	write_status(philo, STATUS_EATING);
	sleep_philo(table->time_to_eat);
	philo->times_ate++;
	sem_post(table->forks);
	sem_post(table->forks);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	monitor_thread;

	philo = (t_philo *)arg;
	pthread_create(&monitor_thread, NULL, philo_monitor, philo);
	pthread_detach(monitor_thread);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eat(philo);
		if (philo->table->must_eat_count != -1
			&& philo->times_ate >= philo->table->must_eat_count)
			exit(0);
		write_status(philo, STATUS_SLEEPING);
		sleep_philo(philo->table->time_to_sleep);
		write_status(philo, STATUS_THINKING);
	}
	return (NULL);
}
