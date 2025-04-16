/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:25:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/16 20:54:51 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	unsigned int words;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	char **result;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
		}
		i++;
	}

	words++;

	result = (char **)malloc(sizeof(char *) * (words + 1));

	if (!result)
		return (NULL);

	i = 0;
	j = 0;
	k = 0;

	while (s[j])
	{
		if (s[j] == c)
		{
			result[k] = ft_strjoin(s + i, s + j);
			i = j;
			k++;
		}
		j++;
	}
	

	return (result);	
}