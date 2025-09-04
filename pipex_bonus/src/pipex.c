/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/04 15:55:51 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128 + WTERMSIG(status));
}

void	ft_close_pipe(int pipefds[2])
{
	close(pipefds[0]);
	close(pipefds[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int i;
	int		pipefds[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (argc < 5)
		return (1);
	if (pipe(pipefds) == -1)
		return (1);
		i = 0;
		pid1 = fork();
	if (pid1 == 0)
	{
		close(pipefds[0]);
		run_cmd(argv[2], ft_open_file(argv[1], 0), pipefds[1], envp);
	}
	while (i < argc)
	{
		pid_t	pid;

		pid = fork();
		if (pid == 0)
		{
			close(pipefds[0]);
			run_cmd(argv[i + 1], pipefds[1], ft_open_file(argv[i], 1), envp);
		}
		i++;
	}


	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipefds[1]);
		run_cmd(argv[3], pipefds[0], ft_open_file(argv[4], 1), envp);
	}
	
	ft_close_pipe(pipefds);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (get_exit_status(status));
}
