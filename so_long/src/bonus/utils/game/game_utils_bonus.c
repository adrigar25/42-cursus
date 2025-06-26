/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 12:13:43 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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

void	finish_game(t_env *env)
{
	if (env->img_floor)
		mlx_destroy_image(env->mlx, env->img_floor);
	if (env->img_wall)
		mlx_destroy_image(env->mlx, env->img_wall);
	if (env->img_exit)
		mlx_destroy_image(env->mlx, env->img_exit);
	if (env->img_collectible)
		mlx_destroy_image(env->mlx, env->img_collectible);
	if (env->img_player_right)
		mlx_destroy_image(env->mlx, env->img_player_right);
	if (env->img_player_left)
		mlx_destroy_image(env->mlx, env->img_player_left);
	if (env->img_player_down)
		mlx_destroy_image(env->mlx, env->img_player_down);
	if (env->img_player_up)
		mlx_destroy_image(env->mlx, env->img_player_up);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->map)
		free_map(env->map);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

int	game_loop(t_env *env)
{
	move_enemies(env);
	print_map(env);
	return (0);
}

int	start_game(char *map_file)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->map = open_map(map_file);
	if (!env->map || !check_map(env))
	{
		handle_error(2);
		finish_game(env);
	}
	env->moves = 0;
	env->win_width = ft_strlen(env->map[0]) * TILE_SIZE;
	env->win_height = get_map_height(env->map) * TILE_SIZE;
	env->n_enemies = (ft_strlen(env->map[0]) * get_map_height(env->map)) / 20;
	randomize_enemies(env, env->win_width / TILE_SIZE, env->win_height
		/ TILE_SIZE);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_width, env->win_height,
			"./so_long.c");
	init_images(env);
	print_map(env);
	mlx_hook(env->win, 2, 1L, key_handler, env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
	return (0);
}
