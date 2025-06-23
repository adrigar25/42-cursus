#ifndef SO_LONG_H
#define SO_LONG_H

//UTILS.C
int check_map_file(char *map_file);

//MAP_UTILS.C
int	check_map(char **map);
char	**open_map(char *map_file);

//GAME.C
int	start_game(char *map_file);

#endif