#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 100

typedef struct s_env
{
	void	*mlx;
	char	**map;
	void	*win;
	int		win_width;
	int		win_height;
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_collectible;
	void	*img_player;
	int		player_x;
	int		player_y;
	int		collectibles;
}			t_env;

// UTILS.C
void		free_map(char **map);

// MAP_UTILS.C
int			check_map_file(char *map_file);
int			check_map(char **map);
char		**open_map(char *map_file);
int			get_map_width(char **map);
int			get_map_height(char **map);

// GAME.C
int			start_game(char *map_file);
int			finish_game(t_env *env);

// ERROR_UTILS.C
int			handle_error(int error_code);

#endif