/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:35 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/25 20:14:12 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 53)
		finish_game(env);
	else if (keycode == 13)
		move_player_to(env, env->player_x, env->player_y - 1, 'W');
	else if (keycode == 1)
		move_player_to(env, env->player_x, env->player_y + 1, 'S');
	else if (keycode == 0)
		move_player_to(env, env->player_x - 1, env->player_y, 'A');
	else if (keycode == 2)
		move_player_to(env, env->player_x + 1, env->player_y, 'D');
	return (0);
}
