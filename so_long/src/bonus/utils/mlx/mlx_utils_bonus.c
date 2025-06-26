/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:41 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 22:18:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	*load_texture(void *mlx, char *name, int *width, int *height)
{
	char	path[256];

	ft_strlcpy(path, "textures/", sizeof(path));
	ft_strlcat(path, name, sizeof(path));
	ft_strlcat(path, ".xpm", sizeof(path));
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

void	init_images(t_env *env)
{
	int	i_w;
	int	i_h;

	if (!env->win)
		finish_game(env);
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

void	print_image(t_env *env, void *img, int x, int y)
{
	char	*moves_str;

	if (!img)
		return ;
	if (env->jumping > 0 && (img == env->img_p_d || img == env->img_p_r
			|| img == env->img_p_l || img == env->img_p_u))
	{
		mlx_put_image_to_window(env->mlx, env->win, env->img_p_j, x * TILE_SIZE,
			y * TILE_SIZE);
		env->jumping--;
	}
	if (env->enemy_moved > 0 && (img == env->img_e_d || img == env->img_e_r
			|| img == env->img_e_l || img == env->img_e_u))
	{
		mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
			* TILE_SIZE);
		env->enemy_moved--;
	}
	mlx_put_image_to_window(env->mlx, env->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, "number of moves:");
	moves_str = ft_itoa(env->moves);
	mlx_string_put(env->mlx, env->win, 130, 10, 0xFFFFFF, moves_str);
	free(moves_str);
}

void	print_player(t_env *env, char c, int x, int y)
{
	if (c == 'S' || c == 'P')
		print_image(env, env->img_p_d, x, y);
	else if (c == 'D')
		print_image(env, env->img_p_r, x, y);
	else if (c == 'A')
		print_image(env, env->img_p_l, x, y);
	else if (c == 'W')
		print_image(env, env->img_p_u, x, y);
	else if (c == 'J')
		print_image(env, env->img_p_j, x, y);
	else if (c == 'U')
		print_image(env, env->img_e_u, x, y);
	else if (c == 'I')
		print_image(env, env->img_e_d, x, y);
	else if (c == 'O')
		print_image(env, env->img_e_l, x, y);
	else if (c == 'L')
		print_image(env, env->img_e_r, x, y);
}

int	print_map(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (env->map[++y])
	{
		x = -1;
		while (env->map[y][++x])
		{
			if (env->map[y][x] == '1')
				print_image(env, env->img_wall, x, y);
			else if (env->map[y][x] == '0')
				print_image(env, env->img_floor, x, y);
			else if (env->map[y][x] == 'C')
				print_image(env, env->img_collectible, x, y);
			else if (env->map[y][x] == 'E')
				print_image(env, env->img_exit, x, y);
			else
				print_player(env, env->map[y][x], x, y);
		}
	}
	return (0);
}
