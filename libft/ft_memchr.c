/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:05:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/14 14:10:37 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s2;
	
	s2 = (unsigned char *)s;
	while (s2 && n > 0)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		n--;
		s2++;
	}

	return (NULL);
}