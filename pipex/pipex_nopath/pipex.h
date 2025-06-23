/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:02:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 22:25:19 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_redir_in_out(int fd, int in_or_out);
int		ft_open_file(const char *filename, int in_or_out);
char	**cmd_parse(char *cmd);
char	*get_cmd_path(char *cmd, char **env);
char	**split_shell_args(const char *s);

#endif