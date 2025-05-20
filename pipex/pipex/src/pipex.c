/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 17:28:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex.h"

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

void	run_cmd(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	*sh_argv[4];

	sh_argv[0] = "sh";
	sh_argv[1] = "-c";
	sh_argv[2] = (char *)cmd;
	sh_argv[3] = NULL;
	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	if (execve("/bin/sh", sh_argv, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(127);
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
	if (pid == 0)
	{
		close(pipefds[0]);
		run_cmd(argv[2], ft_open_file(argv[1], 0), pipefds[1], envp);
	}
	close(pipefds[1]);
	run_cmd(argv[3], pipefds[0], ft_open_file(argv[4], 1), envp);
	return (1);
}
