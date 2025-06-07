/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/07 19:01:30 by agarcia          ###   ########.fr       */
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

	// printf("get_cmd_path: cmd = %s\n", cmd);
	// printf("get_cmd_path: env[0] = %s\n", env[0]);
	// printf("get_cmd_path: PATH = %s\n", my_getenv(env, "PATH"));
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

char	**cmd_parse(char *str)
{
	int		i;
	int		j;
	int		k;
	int		opt_count;
	int		arg_count;
	int		opt_i;
	int		argc;
	int		start;
	int		end;
	char	*cmd;
	char	**result;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	opt_count = 0;
	arg_count = 0;
	opt_i = 0;
	argc = 0;
	start = 0;
	end = 0;
	cmd = NULL;
	result = NULL;
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i + j] && str[i + j] != ' ')
		j++;
	cmd = malloc(j + 1);
	if (!cmd)
		return (NULL);
	ft_memcpy(cmd, str + i, j);
	cmd[j] = '\0';
	i += j;
	// Saltar espacios después del comando
	while (str[i] == ' ')
		i++;
	// Guardar opciones (todas seguidas que empiecen por '-')
	opt_count = 0, opt_i = i;
	while (str[i] == '-' && str[i + 1] && str[i] != '\0')
	{
		j = 0;
		while (str[i + j] && str[i + j] != ' ')
			j++;
		opt_count++;
		i += j;
		while (str[i] == ' ')
			i++;
	}
	// Contar argumentos
	arg_count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		arg_count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	// Reservar espacio para el array final
	result = malloc((1 + opt_count + arg_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	argc = 0;
	result[argc++] = cmd;
	// Guardar opciones
	i = opt_i;
	k = 0;
	while (k < opt_count)
	{
		while (str[i] == ' ')
			i++;
		j = 0;
		while (str[i + j] && str[i + j] != ' ')
			j++;
		result[argc] = malloc(j + 1);
		if (!result[argc])
			return (NULL);
		ft_memcpy(result[argc], str + i, j);
		result[argc][j] = '\0';
		argc++;
		i += j;
		k++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i])
	{
		start = i;
		end = ft_strlen(str) - 1;
		// Quitar comillas externas si existen y NO están escapadas
		if ((str[start] == '\'' && str[end] == '\'') || (str[start] == '"'
				&& str[end] == '"' && (end == 0 || str[end - 1] != '\\')))
		{
			start++;
			end--;
		}
		result[argc] = ft_substr(str, start, end - start + 1);
		if (!result[argc])
			return (NULL);
		argc++;
	}
	result[argc] = NULL;
	// Reemplazar \" por " y \' por ' en cada argumento
	for (int x = 0; result[x]; x++)
	{
		tmp = unescape_quotes(result[x]);
		free(result[x]);
		result[x] = tmp;
	}
	return (result);
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
