/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/18 13:44:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_open_file(const char *filename, int in_or_out)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (in_or_out == 0)
			perror("pipex: input");
		else
			perror("pipex: output");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	child(char **argv, int pipefds[2], char **envp)
{
	char	*sh1_argv[] = {"sh", "-c", argv[2], NULL};

	ft_redir_in_out(ft_open_file(argv[1], 0), 0);
	ft_redir_in_out(pipefds[1], 1);
	close(pipefds[0]);
	if (execve("/bin/sh", sh1_argv, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(sh1_argv[2], 2);
		exit(0);
	}
}

void	parent(char **argv, int pipefds[2], char **envp)
{
	char	*sh2_argv[] = {"sh", "-c", argv[3], NULL};

	ft_redir_in_out(pipefds[0], 0);
	ft_redir_in_out(ft_open_file(argv[4], 1), 1);
	close(pipefds[1]);
	if (execve("/bin/sh", sh2_argv, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(sh2_argv[2], 2);
		exit(0);
	}
}

int	main(int argn, char **argv, char **envp)
{
	int		pipefds[2];
	pid_t	pid;

	if (argn < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	if (pipe(pipefds) == -1)
		return (perror("Error creating pipe"), close(pipefds[0]),
			close(pipefds[1]), 1);
	pid = fork();
	if (pid == -1)
		return (close(pipefds[0]), close(pipefds[1]), 1);
	if (!pid)
		child(argv, pipefds, envp);
	parent(argv, pipefds, envp);
	return (1);
}
