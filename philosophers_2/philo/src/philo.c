/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:18:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/03 23:34:18 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ---------------- PRIORIDAD POR HAMBRE -------------------
   Cada filósofo señala su intención de comer con wants_to_eat.
   La variable table->current_turn indica el filósofo que puede coger tenedores.
   select_hungriest_id devuelve el filósofo que más tiempo ha esperado.
------------------------------------------------------------ */

int	init_table(t_table *table, int argc, char **argv)
{
	if (!table || argc < 5)
		return (0);
	table->n_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]) * 1000;
	table->time_to_eat = ft_atoi(argv[3]) * 1000;
	table->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	if (table->n_philos <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (0);
	mutex_handle(&table->write_lock, MUTEX_INIT);
	mutex_handle(&table->sim_stop_lock, MUTEX_INIT);
	mutex_handle(&table->table_lock, MUTEX_INIT);
	table->sim_stop = 0;
	table->all_threads_created = 0;
	table->threads_running = 0;
	return (1);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->n_philos)
		mutex_handle(&table->forks[i++], MUTEX_INIT);
	return (0);
}

t_philo	*init_philos(int n_philos, t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * n_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < n_philos)
	{
		philos[i].table = table;
		philos[i].id = i + 1;
		philos[i].times_ate = 0;
		philos[i].full = 0;
		philos[i].last_meal_time = 0;
		philos[i].table = table;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % n_philos;
		mutex_handle(&philos[i].philo_lock, MUTEX_INIT);
		i++;
	}
	return (philos);
}

int	write_status(t_philo *philo, t_table *table, const char *status)
{
	int					is_died;
	static int			died_flag = 0;
	static const char	*clocks[] = {"🕛", "🕐", "🕑", "🕒", "🕓", "🕔", "🕕", "🕖",
			"🕗", "🕘", "🕙", "🕚"};
	static int			idx = 0;
	const char			*emoji;
	const char			*end_emoji = "";

	is_died = (ft_strcmp(status, STATUS_DIED) == 0);
	if (ft_strcmp(status, STATUS_FORK) == 0)
		end_emoji = " [✊🍴]";
	else if (ft_strcmp(status, STATUS_EAT) == 0)
		end_emoji = " [😲🍽️ ]";
	else if (ft_strcmp(status, STATUS_SLEEP) == 0)
		end_emoji = " [😴🌚]";
	else if (ft_strcmp(status, STATUS_THINK) == 0)
		end_emoji = " [🤔💭]";
	else if (is_died)
		end_emoji = " [ ☠️  ]";
	mutex_handle(&table->write_lock, MUTEX_LOCK);
	emoji = clocks[idx];
	idx = (idx + 1) % (int)(sizeof(clocks) / sizeof(clocks[0]));
	if (is_died)
		died_flag = 1;
	if (died_flag && !is_died)
	{
		mutex_handle(&table->write_lock, MUTEX_UNLOCK);
		return (1);
	}
	if (debug == 10)
		printf("%s  %5ld ms   %2d  %-22s%s\n", emoji,
			get_timestamp(table->start_time), philo->id, status, end_emoji);
	else
		printf("%ld %u %s\n", get_timestamp(table->start_time), philo->id,
			status);
	mutex_handle(&table->write_lock, MUTEX_UNLOCK);
	return (1);
}

void	*solo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads_running(philo->table);
	set_ulong(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_US));
	increment_long(&philo->table->table_lock, &philo->table->threads_running);
	write_status(philo, philo->table, STATUS_FORK);
	while (!simulation_stopped(philo->table))
		usleep(1000);
	return (NULL);
}
int	eat(t_philo *philo)
{
	unsigned int	ate;

	if (!philo)
		return (0);
	if (get_int(&philo->table->sim_stop_lock, &philo->table->sim_stop))
		return (0);
	if (philo->id % 2 == 0)
	{
		mutex_handle(&philo->table->forks[philo->right_fork], MUTEX_LOCK);
		write_status(philo, philo->table, STATUS_FORK);
		mutex_handle(&philo->table->forks[philo->left_fork], MUTEX_LOCK);
		write_status(philo, philo->table, STATUS_FORK);
	}
	else
	{
		mutex_handle(&philo->table->forks[philo->left_fork], MUTEX_LOCK);
		write_status(philo, philo->table, STATUS_FORK);
		mutex_handle(&philo->table->forks[philo->right_fork], MUTEX_LOCK);
		write_status(philo, philo->table, STATUS_FORK);
	}
	if (get_int(&philo->table->sim_stop_lock, &philo->table->sim_stop))
	{
		mutex_handle(&philo->table->forks[philo->right_fork], MUTEX_UNLOCK);
		mutex_handle(&philo->table->forks[philo->left_fork], MUTEX_UNLOCK);
		return (0);
	}
	set_ulong(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_US));
	write_status(philo, philo->table, STATUS_EAT);
	increment_uint(&philo->philo_lock, &philo->times_ate);
	if (philo->table->must_eat_count != -1)
	{
		ate = get_uint(&philo->philo_lock, &philo->times_ate);
		if ((int)ate >= philo->table->must_eat_count)
			set_long(&philo->philo_lock, &philo->full, 1);
	}
	ft_usleep(philo->table->time_to_eat, philo->table);
	mutex_handle(&philo->table->forks[philo->right_fork], MUTEX_UNLOCK);
	mutex_handle(&philo->table->forks[philo->left_fork], MUTEX_UNLOCK);
	return (1);
}

// en philo.c
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
	// Duerme el tiempo COMPLETO, sin factor
	ft_usleep(time_to_think, philo->table);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	table = philo->table;
	if (!table)
		return (NULL);
	wait_all_threads_running(table);
	increment_long(&table->table_lock, &table->threads_running);
	desync_philos(philo);
	set_ulong(&philo->philo_lock, &philo->last_meal_time, get_time(TIME_US));
	while (!simulation_stopped(table))
	{
		if (get_long(&philo->philo_lock, &philo->full))
			break ;
		eat(philo);
		write_status(philo, table, STATUS_SLEEP);
		ft_usleep(table->time_to_sleep, table);
		think(philo, 1);
	}
	return (NULL);
}

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine,
				(void *)&table->philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	cleanup_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	if (table->forks)
	{
		while (i < table->n_philos)
		{
			mutex_handle(&table->forks[i], MUTEX_DESTROY);
			if (table->philos)
			{
				mutex_handle(&table->philos[i].philo_lock, MUTEX_DESTROY);
			}
			i++;
		}
	}
	mutex_handle(&table->write_lock, MUTEX_DESTROY);
	mutex_handle(&table->sim_stop_lock, MUTEX_DESTROY);
	mutex_handle(&table->table_lock, MUTEX_DESTROY);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	free(table);
}

t_table	*init_data(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (!init_table(table, argc, argv))
	{
		free(table);
		return (NULL);
	}
	printf("MESA INICIALIZADA:\n");
	printf("\nFORKS INICIALIZADOS:\n");
	if (init_forks(table))
	{
		cleanup_table(table);
		return (NULL);
	}
	printf("PHILOSOFOS INICIALIZADOS:\n");
	table->philos = init_philos(table->n_philos, table);
	if (!table->philos)
	{
		cleanup_table(table);
		return (NULL);
	}
	return (table);
}

int	start_simulation(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		printf("id: %d, lfork: %d, rfork: %d\n", table->philos[i].id,
			table->philos[i].left_fork, table->philos[i].right_fork);
		i++;
	}
	set_long(&table->table_lock, &table->start_time, get_time(TIME_US));
	i = 0;
	while (i < table->n_philos)
	{
		set_ulong(&table->philos[i].philo_lock,
			&table->philos[i].last_meal_time, table->start_time);
		i++;
	}
	if (table->n_philos == 1)
	{
		pthread_create(&table->philos[0].thread, NULL, solo_routine,
			(void *)&table->philos[0]);
	}
	else
	{
		create_threads(table);
	}
	set_int(&table->table_lock, &table->all_threads_created, 1);
	pthread_create(&table->monitor_thread, NULL, monitor_simulation, table);
	i = -1;
	while (++i < table->n_philos)
		pthread_join(table->philos[i].thread, NULL);
	set_int(&table->sim_stop_lock, &table->sim_stop, 1);
	pthread_join(table->monitor_thread, NULL);
	return (1);
}
