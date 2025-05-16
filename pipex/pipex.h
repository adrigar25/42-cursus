/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:02:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/16 22:36:15 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_exec_command(char *com, char **args, int infd, int outfd,
			char **envp);

void	ft_redir_in(int fd);
void	ft_redir_out(int fd);
void	ft_close_fd(int fd);

char	*ft_strdup(const char *s1);
char	**ft_split(const char *str, char delimiter);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif