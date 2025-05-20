/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 22:36:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex.h"

void	run_cmd(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	**args;
	char	*path;

	args = cmd_parse(cmd);
	for (int i = 0; args[i]; i++)
		printf("args[%d]: %s\n", i, args[i]);
	if (!args || !args[0])
		exit(127);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
		path = get_cmd_path(args[0], envp);
	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	if (!path || execve(path, args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(args[0], 2);
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
