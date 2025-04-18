/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:03:35 by agarcia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 16:58:30 by agarcia          ###   ########.fr       */
=======
/*   Updated: 2025/04/15 16:44:48 by agarcia          ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
<<<<<<< HEAD
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
=======
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }

    if ((char)c == '\0')
        return ((char *)s);

    return (0);
}
>>>>>>> origin/main
