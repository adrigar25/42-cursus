/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/14 16:25:56 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
		write(2, "pipex: ", 7);
		perror(filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_redir_in_out(int fd, int in_or_out)
{
	int	status;

	if (in_or_out)
		status = dup2(fd, STDOUT_FILENO);
	else
		status = dup2(fd, STDIN_FILENO);
	if (status == -1)
		exit(EXIT_FAILURE);
}
