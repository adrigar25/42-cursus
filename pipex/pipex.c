/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/16 22:52:49 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argn, char **argv, char **envp)
{
	int		filefds[2];
	int		pipefds[2];
	pid_t	pids[2];
	char	*sh1_argv[] = {"sh", "-c", argv[2], NULL};
	char	*sh2_argv[] = {"sh", "-c", argv[3], NULL};
	int		status;

	if (argn < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	filefds[0] = open(argv[1], O_RDONLY);
	filefds[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(pipefds) == -1)
		return (perror("Error creating pipe"), ft_close_fd(filefds[0]),
			ft_close_fd(filefds[1]), 1);
	pids[0] = fork();
	if (pids[0] == -1)
	{
		return (ft_close_fd(filefds[0]), ft_close_fd(filefds[1]), 1);
	}
	else if (pids[0] == 0)
	{
		ft_redir_in(filefds[0]);
		ft_redir_out(pipefds[1]);
		ft_close_fd(pipefds[0]);
		ft_close_fd(pipefds[1]);
		ft_close_fd(filefds[0]);
		ft_close_fd(filefds[1]);
		if (execve("/bin/sh", sh1_argv, envp) == -1)
			exit(EXIT_FAILURE);
	}
	pids[1] = fork();
	if (pids[1] == -1)
	{
		return (ft_close_fd(filefds[0]), ft_close_fd(filefds[1]), 1);
	}
	else if (pids[1] == 0)
	{
		ft_redir_in(pipefds[0]);
		ft_redir_out(filefds[1]);
		ft_close_fd(pipefds[0]);
		ft_close_fd(pipefds[1]);
		ft_close_fd(filefds[0]);
		ft_close_fd(filefds[1]);
		if (execve("/bin/sh", sh2_argv, envp) == -1)
			exit(EXIT_FAILURE);
	}
	ft_close_fd(pipefds[0]);
	ft_close_fd(pipefds[1]);
	ft_close_fd(filefds[0]);
	ft_close_fd(filefds[1]);
	waitpid(pids[0], NULL, 0);
	waitpid(pids[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
