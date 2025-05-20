/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:01:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/20 00:02:43 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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

	paths = ft_split(my_getenv(env, "PATH"), ':');
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		else
		{
			free(path);
			free(*paths);
		}
		paths++;
	}
	return (path);
}

char	**cmd_parse(char *str)
{
    int		i = 0, j = 0, argc = 0, k;
    char	*cmd = NULL;
    char	**result = NULL;

    // Saltar espacios iniciales
    while (str[i] == ' ')
        i++;
    // Guardar comando
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
    int opt_count = 0, opt_i = i;
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
    int arg_count = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (!str[i])
            break;
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
    for (k = 0; k < opt_count; k++)
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
    }
    // Guardar argumentos (todo el resto como un solo argumento)
    while (str[i] == ' ')
        i++;
    if (str[i])
    {
        result[argc] = ft_strdup(str + i);
        if (!result[argc])
            return (NULL);
        argc++;
    }
    result[argc] = NULL;
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
		if (in_or_out == 0)
			perror("pipex: input");
		else
			perror("pipex: output");
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
