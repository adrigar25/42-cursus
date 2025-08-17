/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:53:08 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/04 18:04:39 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	destroy_image(void *mlx, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

void	clear_images(t_env *env)
{
	destroy_image(env->mlx, (void **)&env->img_floor);
	destroy_image(env->mlx, (void **)&env->img_wall);
	destroy_image(env->mlx, (void **)&env->img_exit);
	destroy_image(env->mlx, (void **)&env->img_collectible);
	destroy_image(env->mlx, (void **)&env->img_p_r);
	destroy_image(env->mlx, (void **)&env->img_p_l);
	destroy_image(env->mlx, (void **)&env->img_p_d);
	destroy_image(env->mlx, (void **)&env->img_p_u);
	destroy_image(env->mlx, (void **)&env->img_p_j);
	destroy_image(env->mlx, (void **)&env->img_e_r);
	destroy_image(env->mlx, (void **)&env->img_e_l);
	destroy_image(env->mlx, (void **)&env->img_e_d);
	destroy_image(env->mlx, (void **)&env->img_e_u);
}

void	*load_texture(void *mlx, char *name, int *width, int *height)
{
	char	path[256];

	ft_strlcpy(path, "imgs/", sizeof(path));
	ft_strlcat(path, name, sizeof(path));
	ft_strlcat(path, ".xpm", sizeof(path));
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

void	init_images(t_env *env)
{
	int	i_w;
	int	i_h;

	if (!env->win)
		finish_game(env, 0);
	i_h = TILE_SIZE;
	i_w = TILE_SIZE;
	env->img_floor = load_texture(env->mlx, "floor", &i_w, &i_h);
	env->img_wall = load_texture(env->mlx, "wall", &i_w, &i_h);
	env->img_exit = load_texture(env->mlx, "exit_1", &i_w, &i_h);
	env->img_collectible = load_texture(env->mlx, "collectible", &i_w, &i_h);
	env->img_p_d = load_texture(env->mlx, "player_down", &i_w, &i_h);
	env->img_p_l = load_texture(env->mlx, "player_left", &i_w, &i_h);
	env->img_p_r = load_texture(env->mlx, "player_right", &i_w, &i_h);
	env->img_p_u = load_texture(env->mlx, "player_up", &i_w, &i_h);
	env->img_p_j = load_texture(env->mlx, "player_jump", &i_w, &i_h);
	env->img_e_d = load_texture(env->mlx, "enemy_down", &i_w, &i_h);
	env->img_e_l = load_texture(env->mlx, "enemy_left", &i_w, &i_h);
	env->img_e_r = load_texture(env->mlx, "enemy_right", &i_w, &i_h);
	env->img_e_u = load_texture(env->mlx, "enemy_up", &i_w, &i_h);
}
