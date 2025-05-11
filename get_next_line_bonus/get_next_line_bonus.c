/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:09:47 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/11 15:42:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_gnldelone(t_gnl *gnl)
{
	if (!gnl)
		return ;
	if (gnl->reminder)
	{
		free(gnl->reminder);
		gnl->reminder = NULL;
	}
	free(gnl);
	gnl = NULL;
}

t_gnl	*ft_gnladd_back_gnlnew(t_gnl **gnl, int fd)
{
	t_gnl	*new_node;
	t_gnl	*last;

	if (!gnl)
		return (NULL);
	new_node = malloc(sizeof(t_gnl));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->reminder = NULL;
	new_node->next = NULL;
	if (!*gnl)
	{
		*gnl = new_node;
		return (new_node);
	}
	last = *gnl;
	while (last->next)
		last = last->next;
	last->next = new_node;
	return (new_node);
}

static char	*ft_extract_line(t_gnl *gnl)
{
	char	*line;
	char	*new_reminder;
	size_t	i;
	size_t	len;

	if (!gnl || !gnl->reminder || !*gnl->reminder)
		return (NULL);
	i = 0;
	while (gnl->reminder[i] && gnl->reminder[i] != '\n')
		i++;
	len = i + (gnl->reminder[i] == '\n');
	line = malloc(len + 1);
	if (!line)
		return (free(gnl->reminder), gnl->reminder = NULL, NULL);
	i = 0;
	while (i < len)
	{
		line[i] = gnl->reminder[i];
		i++;
	}
	line[i] = '\0';
	if (gnl->reminder[len] == '\0')
		return (free(gnl->reminder), gnl->reminder = NULL, line);
	new_reminder = ft_strdup(gnl->reminder + len);
	if (!new_reminder)
		return (free(line), free(gnl->reminder), gnl->reminder = NULL, NULL);
	free(gnl->reminder);
	gnl->reminder = new_reminder;
	return (line);
}

static char	*ft_read_until_nl(int fd, t_gnl *gnl)
{
	char	*temp;
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(gnl->reminder, buffer);
		if (!temp)
			return (NULL);
		gnl->reminder = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (gnl->reminder);
}

char	*get_next_line(int fd)
{
	static t_gnl	*gnl_list;
	t_gnl			*current;
	t_gnl			*prev;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = gnl_list;
	prev = NULL;
	while (current && current->fd != fd)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
	{
		current = ft_gnladd_back_gnlnew(&gnl_list, fd);
		if (!current)
			return (NULL);
	}
	if (!ft_read_until_nl(fd, current))
	{
		if (prev)
			prev->next = current->next;
		else
			gnl_list = current->next;
		return (ft_gnldelone(current), NULL);
	}
	line = ft_extract_line(current);
	if (!line)
	{
		if (prev)
			prev->next = current->next;
		else
			gnl_list = current->next;
		return (ft_gnldelone(current), NULL);
	}
	return (line);
}
