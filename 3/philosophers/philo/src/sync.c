/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:05:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 09:36:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	wait_all_threads_created(t_table *table)
{
	while (!get_int(&table->table_lock, &table->all_threads_created))
		;
}

void	wait_all_threads_running(t_table *table)
{
	while (get_int(&table->table_lock,
			&table->threads_running) < (long)table->n_philos)
		ft_usleep(1000, table);
}

void	desync_philos(t_philo *philo)
{
	if (!philo || !philo->table)
		return ;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat * 500, philo->table);
}
