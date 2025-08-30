/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:12:28 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/30 12:15:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	if (env->mlx)
		free(env->mlx);
	if (env->map)
		free_map(env->map);
	free(env);
	handle_error(error);
	exit(0);
}

int	game_close(t_env *env)
{
	finish_game(env, 0);
	return (0);
}
