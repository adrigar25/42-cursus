/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 17:31:02 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"

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
	char	*sh_argv[] = {"sh", "-c", (char *)cmd, NULL};

	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	if (execve("/bin/sh", sh_argv, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(127);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		prev_fd;
	int		pipefd[2];
	pid_t	pid;
	int		i;

	if (argc < 5)
		return (write(2, "Usage: ./pipex infile cmd1 ... cmdn outfile\n", 44),
			1);
	infile = ft_open_file(argv[1], 0);
	outfile = ft_open_file(argv[argc - 1], 1);
	prev_fd = infile;
	i = 2;
	while (i < argc - 2)
	{
		if (pipe(pipefd) == -1)
			return (perror("pipe"), 1);
		pid = fork();
		if (pid == 0)
		{
			dup2(prev_fd, 0);
			dup2(pipefd[1], 1);
			close(pipefd[0]);
			close(pipefd[1]);
			run_cmd(argv[i], 0, 1, envp);
		}
		close(pipefd[1]);
		if (prev_fd != infile)
			close(prev_fd);
		prev_fd = pipefd[0];
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(prev_fd, 0);
		dup2(outfile, 1);
		run_cmd(argv[argc - 2], 0, 1, envp);
	}
	close(prev_fd);
	close(outfile);
	while (wait(NULL) > 0)
		;
	return (0);
}
