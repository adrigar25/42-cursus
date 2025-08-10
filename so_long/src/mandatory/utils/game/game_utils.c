/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/05 13:43:39 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_collectibles(t_env *env)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	if (!env->map)
		return (0);
	while (env->map[i])
	{
		j = 0;
		while (env->map[i][j])
		{
			if (env->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	env->collectibles = count;
	return (count);
}

void	finish_game(t_env *env, int error)
{
	if (!env)
		exit(1);
	clear_images(env);
	if (env->win && env->mlx)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
	}
	if (env->map)
		free_map(env->map);
	free(env);
	handle_error(error);
	exit(0);
}

int	close_program(t_env *env)
{
	finish_game(env, 0);
	return (0);
}

void	start_game(char *map_file)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env || !ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
		finish_game(env, 1);
	env->map = open_map(map_file);
	if (!env->map)
		finish_game(env, 1);
	if (!check_map(env))
		finish_game(env, 2);
	env->moves = 0;
	env->win_width = ft_strlen(env->map[0]) * TILE_SIZE;
	env->win_height = get_map_height(env->map) * TILE_SIZE;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_width, env->win_height,
			"./so_long.c");
	mlx_hook(env->win, 2, 1L, key_handler, env);
	mlx_hook(env->win, 17, 1L, close_program, env);
	mlx_loop_hook(env->mlx, print_map, env);
	mlx_loop(env->mlx);
}
