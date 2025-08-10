/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:30:51 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/05 16:07:00 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	count_args(char *str)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			i = skip_to_quote(str, i, quote);
			if (str[i])
				i++;
		}
		else
			while (str[i] && str[i] != ' ')
				i++;
		count++;
	}
	return (count);
}

int	skip_spaces(const char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

char	*parse_argument(char *str, int *i)
{
	int		start;
	int		len;
	char	quote;
	char	*tmp;
	char	*unesc;

	*i = skip_spaces(str, *i);
	start = *i;
	if (str[*i] == '\'' || str[*i] == '"')
	{
		quote = str[(*i)++];
		start = *i;
		*i = skip_to_quote(str, *i, quote);
	}
	else
		while (str[*i] && str[*i] != ' ')
			(*i)++;
	len = *i - start;
	tmp = ft_substr(str, start, len);
	unesc = unescape_quotes(tmp);
	free(tmp);
	return (unesc);
}

char	**cmd_parse(char *str)
{
	char	**result;
	int		i;
	int		argc;
	int		count;

	i = 0;
	argc = 0;
	count = count_args(str);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (argc < count)
		result[argc++] = parse_argument(str, &i);
	result[argc] = NULL;
	return (result);
}
