/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:09:47 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/08 23:00:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char **reminder)
{
	char	*line;
	char	*new_reminder;
	size_t	i;

	if (!reminder || !*reminder || !**reminder)
		return (NULL);
	i = 0;
	while ((*reminder)[i] && (*reminder)[i] != '\n')
		i++;
	line = ft_substr(*reminder, 0, i + ((*reminder)[i] == '\n'));
	if (!line)
		return (free(*reminder), *reminder = NULL, NULL);
	new_reminder = ft_strdup(*reminder + i + ((*reminder)[i] == '\n'));
	if (!new_reminder)
		return (free(line), free(*reminder), *reminder = NULL, NULL);
	free(*reminder);
	*reminder = new_reminder;
	return (line);
}

static char	*ft_read_until_nl(int fd, char **reminder)
{
	char	*temp;
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(*reminder), *reminder = NULL, NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*reminder, buffer);
		if (!temp)
			return (free(*reminder), *reminder = NULL, NULL);
		free(*reminder);
		*reminder = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reminder)
		reminder = ft_strdup("");
	if (!reminder)
		return (NULL);
	if (!ft_read_until_nl(fd, &reminder))
		return (NULL);
	line = ft_extract_line(&reminder);
	if (!line)
		return (free(reminder), reminder = NULL, NULL);
	return (line);
}
