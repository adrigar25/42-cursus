/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/08/05 13:44:29 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_error(int error_code)
{
	const char	*msg;

	if (error_code == 0)
		return ;
	if (error_code == 1)
		msg = "Archivo de mapa no encontrado o es inválido";
	else if (error_code == 2)
		msg = "Mapa inválido";
	ft_printf("Error: \n%s\n", msg);
}
