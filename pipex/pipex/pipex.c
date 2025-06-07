/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/07 19:01:59 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"
#include <sys/wait.h>


int	run_cmd(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	**args;
	char	*path;

	args = cmd_parse(cmd);
	if (!args || !args[0])
		exit(127);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
		path = get_cmd_path(args[0], envp);
	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	if(!path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
		return (0);
	}
	if (path && access(path, X_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	if (execve(path, args, envp) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return (0);
}

int	main(int argn, char **argv, char **envp)
{
    int		pipefds[2];
    pid_t	pid1, pid2;
    int		status;

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
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        return (128 + WTERMSIG(status));
    return (1);
}
