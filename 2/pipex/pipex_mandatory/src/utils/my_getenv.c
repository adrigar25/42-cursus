/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:30:48 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/01 16:31:12 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*my_getenv(char **env, const char *str)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
