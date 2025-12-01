/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:30:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/01 18:01:08 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_env_path(char **env)
{
	char	*path_env;
	char	**paths;

	path_env = my_getenv(env, "PATH");
	if (!path_env)
		path_env = ft_strdup("/usr/bin:/bin");
	else
		path_env = ft_strdup(path_env);
	paths = ft_split(path_env, ':');
	free(path_env);
	return (paths);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	*temp;
	char	**paths;
	char	*path;
	int		i;

	paths = get_env_path(env);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free_char_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_char_array(paths);
	return (NULL);
}
