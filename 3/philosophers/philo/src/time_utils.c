/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:39:04 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 03:15:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

long	get_time(int unit)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	if (unit == TIME_US)
		return (v.tv_sec * 1000000L + v.tv_usec);
	return (v.tv_sec * 1000L + v.tv_usec / 1000L);
}

long	get_timestamp(long start_time)
{
	return ((get_time(TIME_MS) - start_time));
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;

	start = get_time(TIME_US);
	while (get_time(TIME_US) - start < usec)
	{
		if (simulation_stopped(table))
			break ;
		usleep(50);
	}
}
