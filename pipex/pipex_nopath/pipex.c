/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/14 16:21:18 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"
#include <sys/wait.h>

int	run_cmd(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	*argv_exec[] = {"/bin/bash", "-c", cmd, NULL};

	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	execve("/bin/bash", argv_exec, envp);
	ft_putstr_fd("pipex: bash: execve failed\n", 2);
	exit(127);
	return (0);
}

int	main(int argn, char **argv, char **envp)
{
	int	pipefds[2];
	int	status1;
	int	status2;

	pid_t pid1, pid2;
	if (argn < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	if (pipe(pipefds) == -1)
		return (perror("Error creating pipe"), 1);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipefds[0]);
		if (run_cmd(argv[2], ft_open_file(argv[1], 0), pipefds[1], envp) == -1)
			exit(127);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipefds[1]);
		if (run_cmd(argv[3], pipefds[0], ft_open_file(argv[4], 1), envp) == -1)
			exit(127);
	}
	close(pipefds[0]);
	close(pipefds[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else if (WIFSIGNALED(status2))
		return (128 + WTERMSIG(status2));
	return (1);
}
