/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:18:42 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/04 01:30:49 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

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
	int					id;
	int					times_ate;
	int					left_fork;
	int					right_fork;
	long				last_meal_time;
	long				full;
	t_table				*table;
	pthread_mutex_t		philo_lock;
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
	int					all_threads_created;
	pthread_mutex_t		table_lock;
	int					threads_running;
}						t_table;

// PHILO

t_table					*init_data(int argc, char **argv);
int						start_simulation(t_table *table);
t_table					*init_data(int argc, char **argv);
int						init_table(t_table *table, int argc, char **argv);
int						init_forks(t_table *table);
int						init_philos(t_table *table);
void					*monitor_simulation(void *arg);
void					wait_all_threads_running(t_table *table);
void					think(t_philo *philo, int print);
int						write_status(t_philo *philo, t_table *table,
							const char *status);
int						all_threads_running(t_table *table);
void					desync_philos(t_philo *philo);

// CLEANUP

void					cleanup_table(t_table *table);

// UTILS

int						ft_atoi(const char *str);
int						ft_isdigit(int c);
int						ft_strcmp(const char *s1, const char *s2);
int						create_threads(t_table *table);
void					cleanup_table(t_table *table);

// PHILO ACTIONS
void					*solo_routine(void *arg);
void					*routine(void *arg);
int						eat(t_philo *philo);
int						sleep_philo(int time_to_sleep, t_table *table);
void					think(t_philo *philo, int print);

// CHECK

int						is_valid_number(const char *str);
int						is_overflow(const char *str);
int						check_args(int argc, char **argv);

// TIME UTILS
# define TIME_MS 1
# define TIME_US 2

long					get_time(int unit);
long					get_timestamp(long start_time);
void					ft_usleep(long usec, t_table *table);

// MUTEX UTILS
void					set_int(pthread_mutex_t *mutex, int *dest, int value);
int						get_int(pthread_mutex_t *mutex, int *src);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *src);
unsigned int			get_uint(pthread_mutex_t *mutex, unsigned int *src);
void					set_ulong(pthread_mutex_t *mutex, unsigned long *dest,
							unsigned long value);
unsigned long			get_ulong(pthread_mutex_t *mutex, unsigned long *src);
void					increment_int(pthread_mutex_t *mutex, int *value);
void					increment_long(pthread_mutex_t *mutex, long *value);
int						simulation_stopped(t_table *table);

// SYNC

void					wait_all_threads_created(t_table *table);
void					wait_all_threads_running(t_table *table);
#endif