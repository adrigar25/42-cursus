/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:26:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/29 15:11:04 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (*argv[i] < '0' || *argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->n_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->n_philos;
		philo->fork[1] = philo->id;
	}
}

int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo *) * table->n_philos);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->table = table;
		table->philos[i]->id = i;
		table->philos[i]->times_ate = 0;
		assign_forks(table->philos[i]);
		i++;
	}
	return (1);
}
int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (0);
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->write_lock, NULL))
		return (0);
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!init_forks(table) || !init_mutexes(table) || !init_philos(table))
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

int	init_simulation(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = get_time();
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, philo_routine,
				table->philos[i]))
			return (0);
		i++;
	}
	if (table->n_philos > 1)
	{
		if (!pthread_create(&table->monitor_thread, NULL, monitor_routine,
				table))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_arguments(argc, argv))
	{
		printf("Error: Invalid arguments\n");
		printf("Usage: ");
		printf("%s n_philos time_to_die time_to_eat time_to_sleep [must_eat_count]\n",
			argv[0]);
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	init_table(table, argc, argv);
	// init_simulation(table);
	printf("Philosopher count: %d\n", table->n_philos);
	printf("Time to die: %d\n", table->time_to_die);
	printf("Time to eat: %d\n", table->time_to_eat);
	printf("Time to sleep: %d\n", table->time_to_sleep);
	printf("Must eat: %d\n", table->must_eat_count);
	printf("Start time: %ld\n", table->start_time);
	return (0);
}
