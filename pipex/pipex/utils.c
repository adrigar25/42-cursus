/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/20 16:21:02 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

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

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path;
	char	**paths;

	if (!env || !my_getenv(env, "PATH"))
		return (NULL);
	paths = ft_split(my_getenv(env, "PATH"), ':');
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
		else
		{
			free(path);
			free(*paths);
		}
		paths++;
	}
	return (NULL);
}

char	*strip_quotes(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '\'' && str[len - 1] == '\'') || (str[0] == '"'
				&& str[len - 1] == '"')))
		return (ft_substr(str, 1, len - 2));
	return (ft_strdup(str));
}

char	*unescape_quotes(const char *str)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0, j = 0;
	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\\' && (str[i + 1] == '"' || str[i + 1] == '\''))
			res[j++] = str[++i];
		else
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_open_file(const char *filename, int in_or_out)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "pipex: ", 7);
		perror(filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_redir_in_out(int fd, int in_or_out)
{
	int	status;

	if (in_or_out)
		status = dup2(fd, STDOUT_FILENO);
	else
		status = dup2(fd, STDIN_FILENO);
	if (status == -1)
		exit(EXIT_FAILURE);
}

int	skip_to_quote(const char *str, int i, char quote)
{
    while (str[i] && str[i] != quote)
    {
        if (quote == '"' && str[i] == '\\' && str[i + 1])
            i += 2;
        else
            i++;
    }
    return (i);
}

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

char	**cmd_parse(char *str)
{
	int		count;
	int		i;
	int		j;
	int		argc;
	char	**result;
	char	*tmp;
	char	quote;
	char	*unesc;

	count = count_args(str);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	argc = 0;
	while (argc < count)
	{
		while (str[i] == ' ')
			i++;
		j = i;
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			j = i;
			i = skip_to_quote(str, i, quote);
			tmp = ft_substr(str, j, i - j);
			if (quote == '"')
			{
				unesc = unescape_quotes(tmp);
				free(tmp);
				tmp = unesc;
			}
			result[argc++] = tmp;
			if (str[i])
				i++;
		}
		else
		{
			while (str[i] && str[i] != ' ')
				i++;
			result[argc++] = ft_substr(str, j, i - j);
		}
	}
	result[argc] = NULL;
	return (result);
}
