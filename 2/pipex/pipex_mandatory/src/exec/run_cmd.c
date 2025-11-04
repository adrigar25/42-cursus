/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:30:28 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:24 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	run_cmd(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	**args;
	char	*path;

	args = cmd_parse(cmd);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
		path = get_cmd_path(args[0], envp);
	if (!args || !args[0] || !path || access(path, X_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(args[0], 2);
		if (path)
			ft_putstr_fd("\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
		if (path)
			exit(126);
		else
			exit(127);
	}
	ft_redir_in_out(fd_in, 0);
	ft_redir_in_out(fd_out, 1);
	execve(path, args, envp);
	return (0);
}
