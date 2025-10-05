/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:11:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/03 12:50:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

// Mensajes de estado
# define STATUS_FORK "has taken a fork"
# define STATUS_EATING "is eating"
# define STATUS_SLEEPING "is sleeping"
# define STATUS_THINKING "is thinking"
# define STATUS_DIED "died"

// Mensaje de uso
# define USAGE_MSG \
	"Usage: \
	%s n_philos time_to_die time_to_eat time_to_sleep[must_eat_count]\n "

// Estructuras

typedef struct s_philo
{
	int				id;
	int				times_ate;
	pid_t			pid;
	long			last_meal;
	pthread_mutex_t	meal_time_lock;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				sim_stop;

	t_philo			**philos;
	sem_t			*forks;
	sem_t			*write_sem;
	long			start_time;
}					t_table;

// Funciones principales
int					ft_atoi(const char *str);
int					init_table(t_table *table, int argc, char **argv);
int					init_philosophers(t_table *table);
int					init_semaphores(t_table *table);
void				*routine(void *arg);
int					write_status(t_philo *philo, const char *status);

// Utils de tiempo
long				get_time_ms(void);
long				get_timestamp(long start_time);

#endif
