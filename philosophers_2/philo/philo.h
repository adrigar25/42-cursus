/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:18:42 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/21 19:39:56 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# define STATUS_EAT "is eating"
# define STATUS_SLEEP "is sleeping"
# define STATUS_THINK "is thinking"
# define STATUS_FORK "has taken a fork"
# define STATUS_DIED "died"

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		left_fork;
	unsigned int		right_fork;
	unsigned long		last_meal_time;
	t_table				*table;
	pthread_mutex_t		meal_lock;
}						t_philo;

typedef struct s_table
{
	int					n_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	long				start_time;
	int					sim_stop;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		sim_stop_lock;
	pthread_t			monitor_thread;
	pthread_mutex_t		priority_lock;
}						t_table;

// PHILO

int						philosophers(int argc, char **argv);
int						init_table(t_table *table, int argc, char **argv);
int						monitor_simulation(t_table *table);
void					*monitor_thread_fn(void *arg);
int						write_status(t_philo *philo, t_table *table,
							const char *status);

// UTILS

int						ft_atoi(const char *str);
int						ft_isdigit(int c);
int						ft_strcmp(const char *s1, const char *s2);

// CHECK

int						is_valid_number(const char *str);
int						is_overflow(const char *str);
int						check_args(int argc, char **argv);

// TIME UTILS
long					get_time_ms(void);
long					get_timestamp(long start_time);
void					ft_usleep(int ms, t_table *table);
#endif
