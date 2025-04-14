/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:23:15 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/14 14:41:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (len > 0 && big[i] != '\0')
	{
		if (*big == *little)
		{
			j = 0;
			while (big[i + j] == little[j] && len > 0)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
				len--;
			}
		}
		i++;
		len--;
		big++;
	}

	return (NULL);
}
