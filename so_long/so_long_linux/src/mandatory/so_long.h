/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:49 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/28 19:11:19 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libs/ft_printf/ft_printf.h"
# include "../../libs/gnl/get_next_line.h"
# include "../../libs/libft/libft.h"
# include "../../libs/mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILE_SIZE 100

typedef struct s_env
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_wall;
	void	*img_floor;
	void	*img_p_d;
	void	*img_collectible;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		win_width;
	int		win_height;
	char	*title;
	int		collectibles;
	int		moves;
}			t_env;

/* game */
void		start_game(char *map_file);
void		finish_game(t_env *env, int error);
int			count_collectibles(t_env *env);
int			game_close(t_env *env);
int			game_loop(t_env *env);

/* player */
int			get_player_position(t_env *env);
void		move_player_to(t_env *env, int new_x, int new_y);

/* input */

int			key_handler(int keycode, t_env *env);

/* map utils */
char		**open_map(char *map_file);
int			get_map_height(char **map);
void		free_map(char **map);
int			check_map(t_env *env);
int			check_if_playable(char **map, int x, int y);
int			check_rectangular(char **map);
int			check_min_size(char **map);
int			check_wall(char **map);

/* error utils */
void		handle_error(int error_code);

/* mlx utils */
int			close_window(t_env *env);
void		init_images(t_env *env);
int			print_map(t_env *env);
void		print_image(t_env *env, char image, int x, int y);
void		clear_images(t_env *env);

#endif