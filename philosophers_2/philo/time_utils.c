/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:39:04 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/21 16:19:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

long	get_timestamp(long start_time)
{
	return (get_time_ms() - start_time);
}

void	ft_usleep(int ms, t_table *table)
{
	long start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < ms)
	{
		pthread_mutex_lock(&table->sim_stop_lock);
		if (table->sim_stop)
		{
			pthread_mutex_unlock(&table->sim_stop_lock);
			break ;
		}
		pthread_mutex_unlock(&table->sim_stop_lock);
		usleep(100);
	}
}