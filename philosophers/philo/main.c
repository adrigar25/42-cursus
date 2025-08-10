/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:26:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/10 14:17:31 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include <stdio.h>
#include <stdlib.h>

void	init_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&data->philos[i].thread_id, NULL, philo_routine,
			&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}

void	init_table(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return ;
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return ;
	data->someone_died = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->philo_count;
		data->philos[i].data = data;
		i++;
	}
}

void	store_data(t_data *data, int argc, char **argv)
{
	data->philo_count = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->must_eat = (argc == 6) ? atoi(argv[5]) : -1;
}

void	cleanup(t_data *data)
{
	for (int i = 0; i < data->philo_count; i++)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->philos);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		printf("Usage:\n");
		printf("%s number_of_philosophers time_to_die time_to_eat time_to_sleep [data->must_eat]\n",
			argv[0]);
		return (1);
	}
	data = malloc(sizeof(t_data));
	store_data(data, argc, argv);
	data->start_time = get_real_time_ms();
	init_table(data);
	init_simulation(data);
	cleanup(data);
	return (0);
}
