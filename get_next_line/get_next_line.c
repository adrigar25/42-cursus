/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:09:47 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/29 17:52:20 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *remainder;
	char *line;
	char *buffer[BUFFER_SIZE + 1];
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin_free(remainder, buffer);
		if(ft_strchr(remainder, '\n'))
			break;
	}
	

	return (line);
}