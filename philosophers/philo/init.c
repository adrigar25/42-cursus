/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:08:08 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/02 16:39:34 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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
		if (pthread_mutex_init(&table->philos[i]->meal_time_lock, NULL))
			return (0);
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
	if (pthread_mutex_init(&table->sim_stop_lock, NULL))
		return (0);
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	table->n_philos = ft_atoi(argv[1]);
	if (!init_forks(table) || !init_mutexes(table) || !init_philos(table))
		return (0);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat_count = -1;
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	return (1);
}