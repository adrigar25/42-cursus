/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:34:57 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/15 16:43:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strncmp(&s1[i], set, ft_strlen(set)) == 0)
		i++;
	while (s1[j] && ft_strncmp(&s1[j], set, ft_strlen(set)) == 0)
		j--;
	if (i > j)
	{
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, i, j - i + 1);

	str[j - i + 1] = '\0';

	return (str);
}
