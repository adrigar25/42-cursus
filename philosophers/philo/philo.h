/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:11:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/29 15:11:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long				start_time;
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	t_philo				**philos;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*forks;
	pthread_t			monitor_thread;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	time_t				last_meal;
	t_table				*table;
}						t_philo;

// UTILS

long					get_real_time_ms(void);
long					get_timestamp(long start_time);

#endif // PHILO_H
