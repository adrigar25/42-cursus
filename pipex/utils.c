/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/16 22:36:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_redir_in(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error in dup2(fd, STDIN_FILENO)");
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	ft_redir_out(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error in dup2(fd, STDOUT_FILENO)");
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	ft_close_fd(int fd)
{
	if (fd != -1)
	{
		if (close(fd) == -1)
		{
			perror("Error in close(fd)");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_exec_command(char *command_path, char **args, int infd, int outfd,
		char **envp)
{
	ft_redir_in(infd);
	ft_redir_out(outfd);
	if (execve(command_path, args, envp) == -1)
	{
		perror("Error en execve");
		ft_close_fd(infd);
		ft_close_fd(outfd);
		exit(EXIT_FAILURE);
	}
}
