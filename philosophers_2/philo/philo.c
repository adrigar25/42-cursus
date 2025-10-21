/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:18:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/21 19:21:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	init_table(t_table *table, int argc, char **argv)
{
	if (!table || argc < 5)
		return (0);
	table->n_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat_count = -1;
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	return (1);
}

t_philo	create_philo(int id)
{
	t_philo	philo;

	philo.id = id;
	philo.times_ate = 0;
	return (philo);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->n_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	return (0);
}

int	assign_forks(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % table->n_philos;
		i++;
	}
	return (0);
}

t_philo	*init_philos(int n_philos, t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * n_philos);
	if (!philos)
		exit(1);
	i = 0;
	while (i < n_philos)
	{
		philos[i].id = i + 1;
		philos[i].times_ate = 0;
		philos[i].table = table;
		philos[i].last_meal_time = 0;
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		i++;
	}
	assign_forks(table, philos);
	return (philos);
}

int	write_status(t_philo *philo, t_table *table, const char *status)
{
	static const char	*clocks[] = {"🕛", "🕐", "🕑", "🕒", "🕓", "🕔", "🕕", "🕖",
			"🕗", "🕘", "🕙", "🕚"};
	static int			idx = 0;
	const char			*emoji;
	const char			*end_emoji = "";
	int					is_died;

	static int died_flag = 0; // marca si DIET ya se imprimió
	is_died = (ft_strcmp(status, STATUS_DIED) == 0);
	pthread_mutex_lock(&table->sim_stop_lock);
	if (is_died)
		table->sim_stop = 1;
	// para asegurarnos que otros hilos sepan que la simulación terminó
	pthread_mutex_unlock(&table->sim_stop_lock);
	pthread_mutex_lock(&table->write_lock);
	if (died_flag && !is_died) // si DIET ya se imprimió, no imprimimos nada más
	{
		pthread_mutex_unlock(&table->write_lock);
		return (1);
	}
	emoji = clocks[idx];
	idx = (idx + 1) % (int)(sizeof(clocks) / sizeof(clocks[0]));
	if (ft_strcmp(status, STATUS_FORK) == 0)
		end_emoji = " [✊🍴]";
	else if (ft_strcmp(status, STATUS_EAT) == 0)
		end_emoji = " [😲🍽️ ]";
	else if (ft_strcmp(status, STATUS_SLEEP) == 0)
		end_emoji = " [😴🌚]";
	else if (ft_strcmp(status, STATUS_THINK) == 0)
		end_emoji = " [🤔💭]";
	else if (is_died)
	{
		end_emoji = " [ ☠️  ]";
		died_flag = 1;
	}
	printf("%s  %5ld ms   %2d  %-22s%s\n", emoji,
		get_timestamp(table->start_time), philo->id, status, end_emoji);
	pthread_mutex_unlock(&table->write_lock);
	return (1);
}

int	sleep_philo(int duration_ms, t_table *table)
{
	long	start_time;
	long	now;

	start_time = get_time_ms();
	while (1)
	{
		pthread_mutex_lock(&table->sim_stop_lock);
		if (table->sim_stop)
		{
			pthread_mutex_unlock(&table->sim_stop_lock);
			return (0);
		}
		pthread_mutex_unlock(&table->sim_stop_lock);
		now = get_time_ms();
		if ((now - start_time) >= duration_ms)
			break ;
		ft_usleep(1, table);
	}
	return (1);
}
int	solo_routine(t_table *table)
{
	t_philo	*philo;

	philo = &table->philos[0];
	if (!philo)
		return (1);
	write_status(philo, table, STATUS_FORK);
	sleep_philo(table->time_to_die, table);
	write_status(philo, table, STATUS_DIED);
	return (0);
}
int	eat(t_philo *philo, t_table *table)
{
	if (!philo)
		return (0);
	// Revisar si la simulación ya paró antes de agarrar tenedores
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop)
	{
		pthread_mutex_unlock(&table->sim_stop_lock);
		return (0);
	}
	pthread_mutex_unlock(&table->sim_stop_lock);
	// Agarrar tenedores
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		write_status(philo, table, STATUS_FORK);
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		write_status(philo, table, STATUS_FORK);
	}
	else
	{
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		write_status(philo, table, STATUS_FORK);
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		write_status(philo, table, STATUS_FORK);
	}
	// Revisar sim_stop justo antes de comer
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop)
	{
		pthread_mutex_unlock(&table->sim_stop_lock);
		pthread_mutex_unlock(&table->forks[philo->right_fork]);
		pthread_mutex_unlock(&table->forks[philo->left_fork]);
		return (0);
	}
	pthread_mutex_unlock(&table->sim_stop_lock);
	// Comer
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_ms();
	write_status(philo, table, STATUS_EAT);
	philo->times_ate++;
	pthread_mutex_unlock(&philo->meal_lock);
	sleep_philo(table->time_to_eat, table);
	// Soltar tenedores
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	return (1);
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
	if (philo->id % 2)
		ft_usleep(table->time_to_eat / 2, table);
	while (1)
	{
		pthread_mutex_lock(&table->sim_stop_lock);
		if (table->sim_stop)
		{
			pthread_mutex_unlock(&table->sim_stop_lock);
			break ;
		}
		pthread_mutex_unlock(&table->sim_stop_lock);
		if (!eat(philo, table))
			break ;
		// Si comió las veces requeridas, salir
		if (table->must_eat_count != -1
			&& (int)philo->times_ate >= table->must_eat_count)
			break ;
		write_status(philo, table, STATUS_SLEEP);
		if (!sleep_philo(table->time_to_sleep, table))
			break ;
		write_status(philo, table, STATUS_THINK);
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
		ft_usleep(1, table);
		i++;
	}
	return (1);
}

int	philosophers(int argc, char **argv)
{
	t_table	*table;
	int		i;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	if (!init_table(table, argc, argv))
		return (0);
	// t_philo	*philos;
	// This line is commented out as we are using table->philos now
	printf("MESA INICIALIZADA:\n");
	printf("Número de filósofos: %d\n", table->n_philos);
	printf("Tiempo para morir: %d ms\n", table->time_to_die);
	printf("Tiempo para comer: %d ms\n", table->time_to_eat);
	printf("Tiempo para dormir: %d ms\n", table->time_to_sleep);
	if (table->must_eat_count != -1)
		printf("Número de veces que cada filósofo debe comer: %d\n",
			table->must_eat_count);
	printf("\n");
	printf("FORKS INICIALIZADOS:\n");
	init_forks(table);
	printf("PHILOSOFOS INICIALIZADOS:\n");
	table->philos = init_philos(table->n_philos, table);
	i = 0;
	while (i < table->n_philos)
	{
		printf("id: %d, times_ate: %d, left_fork: %d, right_fork: %d\n",
			table->philos[i].id, table->philos[i].times_ate,
			table->philos[i].left_fork, table->philos[i].right_fork);
		i++;
	}
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->sim_stop_lock, NULL);
	table->sim_stop = 0;
	table->start_time = get_time_ms();
	if (table->n_philos == 1)
		return (solo_routine(table));
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].last_meal_time = table->start_time;
		i++;
	}
	if (!create_threads(table))
		return (0);
	i = 0;
	if (pthread_create(&table->monitor_thread, NULL, monitor_thread_fn,
			(void *)table))
		return (0);
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
	free(table->philos);
	free(table);
	return (1);
}
