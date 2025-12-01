/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:53:08 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/29 15:26:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	destroy_image(env->mlx, (void **)&env->img_player_down);
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
	env->img_player_down = load_texture(env->mlx, "player_down", &i_w, &i_h);
}
