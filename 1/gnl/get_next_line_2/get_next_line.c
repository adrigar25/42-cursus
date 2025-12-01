/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/19 18:45:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			r;
	int			i;
	int			j;

	line = NULL;
	r = 1;
	i = 0;
	while (1)
	{
		if (!buf[0])
		{
			r = read(fd, buf, BUFFER_SIZE);
			if (r < 0)
			{
				if (line)
					free(line);
				buf[0] = 0;
				return (NULL);
			}
			if (r == 0)
				return (line);
			buf[r] = 0;
		}
		i = 0;
		while (buf[i] && buf[i] != '\n')
		{
			line = gnl_strjoin(line, buf[i]);
			i++;
		}
		if (buf[i] == '\n')
		{
			line = gnl_strjoin(line, '\n');
			i++;
		}
		j = 0;
		while (buf[i])
			buf[j++] = buf[i++];
		buf[j] = 0;
		if (line && (line[ft_strlen(line) - 1] == '\n' || r == 0))
			break ;
	}
	if (line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
