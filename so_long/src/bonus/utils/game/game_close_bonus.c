/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:12:28 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/27 00:12:51 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	destroy_image(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

void	finish_game(t_env *env)
{
	destroy_image(env->mlx, env->img_floor);
	destroy_image(env->mlx, env->img_wall);
	destroy_image(env->mlx, env->img_exit);
	destroy_image(env->mlx, env->img_collectible);
	destroy_image(env->mlx, env->img_p_r);
	destroy_image(env->mlx, env->img_p_l);
	destroy_image(env->mlx, env->img_p_d);
	destroy_image(env->mlx, env->img_p_u);
	destroy_image(env->mlx, env->img_e_r);
	destroy_image(env->mlx, env->img_e_l);
	destroy_image(env->mlx, env->img_e_d);
	destroy_image(env->mlx, env->img_e_u);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->map)
		free_map(env->map);
	exit(0);
}

int	game_close(t_env *env)
{
	finish_game(env);
	return (0);
}
