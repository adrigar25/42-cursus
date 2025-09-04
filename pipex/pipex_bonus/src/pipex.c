/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>             +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/04 18:29:38 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include <string.h>

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

int	handle_here_doc(char *limiter)
{
	int		pipefd[2];
	char	*line;
	size_t	len;

	len = strlen(limiter);
	if (pipe(pipefd) == -1)
		return (-1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (strncmp(line, limiter, len) == 0 && line[len] == '\n')
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, strlen(line));
		free(line);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

int	ft_child_process(t_ppx *ctx)
{
	int		pipefds[2];
	pid_t	pid;
	int		is_here_doc;
	int		is_first;
	int		is_last;
	int		outfile_fd;

	is_here_doc = (strcmp(ctx->argv[1], "here_doc") == 0);
	is_first = (ctx->i == 2 + is_here_doc);
	is_last = (ctx->i == ctx->argc - 2);
	if (is_last)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (is_here_doc)
				outfile_fd = ft_open_file(ctx->argv[ctx->argc - 1], 2);
			else
				outfile_fd = ft_open_file(ctx->argv[ctx->argc - 1], 1);
			run_cmd(ctx->argv[ctx->i], ctx->infd, outfile_fd, ctx->envp);
		}
		return (0);
	}
	if (pipe(pipefds) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (is_here_doc && is_first)
			run_cmd(ctx->argv[ctx->i], ctx->infd, pipefds[1], ctx->envp);
		else if (!is_here_doc && is_first)
			run_cmd(ctx->argv[ctx->i], ft_open_file(ctx->argv[1], 0),
				pipefds[1], ctx->envp);
		else
			run_cmd(ctx->argv[ctx->i], ctx->infd, pipefds[1], ctx->envp);
	}
	close(pipefds[1]);
	ctx->infd = pipefds[0];
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_ppx	ctx;

	if (argc < 5)
		return (1);
	ctx.argc = argc;
	ctx.argv = argv;
	ctx.envp = envp;
	if (strcmp(argv[1], "here_doc") == 0)
	{
		ctx.infd = handle_here_doc(argv[2]);
		ctx.i = 3;
	}
	else
	{
		ctx.infd = ft_open_file(argv[1], 0);
		ctx.i = 2;
	}
	while (ctx.i < argc - 1)
	{
		if (ft_child_process(&ctx))
			return (1);
		ctx.i++;
	}
	while (wait(&status) > 0)
		;
	return (get_exit_status(status));
}
