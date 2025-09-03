/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:11:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/02 16:35:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

# define STATUS_EATING "is eating"
# define STATUS_SLEEPING "is sleeping"
# define STATUS_THINKING "is thinking"
# define STATUS_FORK "has taken a fork"
# define STATUS_DIED "died"

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
	pthread_mutex_t		sim_stop_lock;
	int					sim_stop;
}						t_table;

typedef struct s_philo
{
	pthread_t					thread;
	unsigned int				id;
	unsigned int				times_ate;
	unsigned int				fork[2];
	time_t						last_meal;
	pthread_mutex_t				meal_time_lock;
	t_table					*table;
}						t_philo;

// TIME UTILS

long					get_time_ms(void);
long					get_timestamp(long start_time);

// WRITE

void					write_status(t_philo *philo, const char *status);

// PHILO ACTIONS

void					*one_philo_routine(t_philo *philo);
void					*philo(void *arg);

// INIT

int						init_philos(t_table *table);
int						init_forks(t_table *table);
int						init_mutexes(t_table *table);
int						init_table(t_table *table, int argc, char **argv);
int						init_simulation(t_table *table);

int						ft_atoi(const char *str);

#endif // PHILO_H
