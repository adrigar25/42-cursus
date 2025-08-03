/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:31:09 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/01 15:31:09 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./../libs/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Function declarations
int		run_cmd(char *cmd, int fd_in, int fd_out, char **envp);
char	*get_cmd_path(char *cmd, char **env);
char	**cmd_parse(char *str);
int		count_args(char *str);
int		skip_to_quote(const char *str, int i, char quote);
char	*strip_quotes(const char *str);
char	*unescape_quotes(const char *str);
int		ft_open_file(const char *filename, int in_or_out);
void	ft_redir_in_out(int fd, int in_or_out);
char	*my_getenv(char **env, const char *str);
void	free_char_array(char **array);

#endif