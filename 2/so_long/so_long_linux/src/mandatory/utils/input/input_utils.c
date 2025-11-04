/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:35 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/03 16:52:41 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 65307)
		finish_game(env, 0);
	else if (keycode == 119)
		move_player_to(env, env->player_x, env->player_y - 1);
	else if (keycode == 115)
		move_player_to(env, env->player_x, env->player_y + 1);
	else if (keycode == 97)
		move_player_to(env, env->player_x - 1, env->player_y);
	else if (keycode == 100)
		move_player_to(env, env->player_x + 1, env->player_y);
	return (0);
}
