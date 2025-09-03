/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:54:47 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/01 16:48:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	write_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->table->write_lock);
	printf("%ld ms %d %s\n", get_timestamp(philo->table->start_time), philo->id,
		status);
	pthread_mutex_unlock(&philo->table->write_lock);
}