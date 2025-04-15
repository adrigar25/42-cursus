/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:11:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/15 16:33:40 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char		*d;
    const unsigned char	*s;

    if (dest == src || n == 0)
        return (dest);

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    while (n--)
        *d++ = *s++;

    return (dest);
}
