/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:05:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/03 23:29:47 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	wait_all_threads_running(t_table *table)
{
	while (!get_int(&table->table_lock, &table->all_threads_created))
		;
}

int	all_threads_running(t_table *table)
{
	int	ret;

	ret = 0;
	mutex_handle(&table->table_lock, MUTEX_LOCK);
	if (table->threads_running >= table->n_philos)
		ret = 1;
	mutex_handle(&table->table_lock, MUTEX_UNLOCK);
	return (ret);
}

void	desync_philos(t_philo *philo)
{
	if (!philo || !philo->table)
		return ;
	if (philo->table->n_philos % 2 == 0 && philo->id % 2 == 0)
		ft_usleep(3e4, philo->table);
}
