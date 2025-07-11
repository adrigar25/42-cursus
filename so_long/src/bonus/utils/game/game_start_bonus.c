/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:12:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/27 00:16:35 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	start_game(char *map_file)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return ;
	env->map = open_map(map_file);
	if (!env->map || !check_map(env))
		finish_game(env);
	env->moves = 0;
	env->win_width = ft_strlen(env->map[0]) * TILE_SIZE;
	env->win_height = get_map_height(env->map) * TILE_SIZE;
	env->n_enemies = (env->win_width / TILE_SIZE * env->win_height / TILE_SIZE)
		/ 20;
	randomize_enemies(env, env->win_width / TILE_SIZE, env->win_height
		/ TILE_SIZE);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_width, env->win_height,
			"./so_long.c");
	init_images(env);
	mlx_hook(env->win, 2, 1L, key_handler, env);
	mlx_hook(env->win, 17, 1L, game_close, env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
}
