/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:11:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/10 13:54:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	long			start_time;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
	pthread_mutex_t	print_mutex;
	int				someone_died;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread_id;
	int				left_fork;
	int				right_fork;
	t_data			*data;
}					t_philo;

long				get_timestamp(t_data *data);
void				*philo_routine(void *arg);
long				get_real_time_ms(void);

#endif // PHILO_H
