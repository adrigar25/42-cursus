/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:26:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/03 12:56:31 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	for (int i = 1; i < argc; i++)
		if (ft_atoi(argv[i]) < 0)
			return (0);
	return (1);
}

static void	wait_processes(t_table *table)
{
	int		status;
	pid_t	pid;

	for (int i = 0; i < table->n_philos; i++)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0 && WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			for (int j = 0; j < table->n_philos; j++)
				kill(table->philos[j]->pid, SIGKILL);
			break ;
		}
	}
}

static int	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_time_ms();
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i]->last_meal = table->start_time;
		table->philos[i]->pid = fork();
		if (table->philos[i]->pid < 0)
			return (0);
		if (table->philos[i]->pid == 0)
		{
			routine(table->philos[i]);
			exit(0);
		}
		i++;
	}
	wait_processes(table);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_arguments(argc, argv))
	{
		printf(USAGE_MSG, argv[0]);
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (!init_table(table, argc, argv))
		return (1);
	if (!start_simulation(table))
		return (1);
	return (0);
}
