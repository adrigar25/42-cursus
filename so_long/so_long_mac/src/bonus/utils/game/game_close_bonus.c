/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:12:28 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/04 17:23:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	finish_game(t_env *env, int error)
{
	clear_images(env);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->map)
		free_map(env->map);
	handle_error(error);
	exit(0);
}

int	game_close(t_env *env)
{
	finish_game(env, 0);
	return (0);
}
