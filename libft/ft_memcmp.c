/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:15:51 by agarcia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 16:58:22 by agarcia          ###   ########.fr       */
=======
/*   Updated: 2025/04/16 16:47:14 by agarcia          ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
<<<<<<< HEAD
	const unsigned char	*s3 = (const unsigned char *)s1;
	const unsigned char	*s4 = (const unsigned char *)s2;

	while (n--)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
	}
	return (0);
=======
    const unsigned char	*s3 = (const unsigned char *)s1;
    const unsigned char	*s4 = (const unsigned char *)s2;

    while (n--)
    {
        if (*s3 != *s4)
            return (*s3 - *s4);
        s3++;
        s4++;
    }
    return (0);
>>>>>>> origin/main
}
