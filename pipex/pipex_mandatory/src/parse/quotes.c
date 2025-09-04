/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:56:30 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/05 16:07:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*unescape_quotes(const char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\\' && (str[i + 1] == '"' || str[i + 1] == '\''))
			i++;
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}

int	skip_to_quote(const char *str, int i, char quote)
{
	while (str[i] && str[i] != quote)
		i += (str[i] == '\\' && str[i + 1]) + 1;
	return (i);
}
