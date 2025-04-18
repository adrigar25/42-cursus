/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:05:37 by agarcia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 17:01:59 by agarcia          ###   ########.fr       */
=======
/*   Updated: 2025/04/16 16:44:23 by agarcia          ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
<<<<<<< HEAD
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
=======
    unsigned char *str = (unsigned char *)s;

    while (n--)
    {
        if (*str == (unsigned char)c)
            return ((void *)str);
        str++;
    }
    return (NULL);
}
>>>>>>> origin/main
