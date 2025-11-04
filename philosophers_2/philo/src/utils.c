/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:39:38 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 01:30:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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
	while (i < table->n_philos && table->forks)
	{
		pthread_mutex_destroy(&table->forks[i]);
		if (table->philos)
			pthread_mutex_destroy(&table->philos[i].philo_lock);
		i++;
	}
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->sim_stop_lock);
	pthread_mutex_destroy(&table->table_lock);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	free(table);
}
