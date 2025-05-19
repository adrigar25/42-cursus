/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 17:29:10 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
