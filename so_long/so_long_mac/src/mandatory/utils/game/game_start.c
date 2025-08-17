/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:12:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/17 14:57:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	start_game(char *map_file)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (!ft_strnstr(&map_file[ft_strlen(map_file) - 4], ".ber", 4))
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
	init_images(env);
	mlx_hook(env->win, 2, 1L, key_handler, env);
	mlx_hook(env->win, 17, 1L, game_close, env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
}
