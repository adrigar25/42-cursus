/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:11:15 by agarcia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 17:00:58 by agarcia          ###   ########.fr       */
=======
/*   Updated: 2025/04/16 17:09:51 by agarcia          ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
<<<<<<< HEAD
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
=======
        
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

>>>>>>> origin/main
	if (d > s && d < s + n)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
<<<<<<< HEAD
=======

>>>>>>> origin/main
	return (dest);
}
