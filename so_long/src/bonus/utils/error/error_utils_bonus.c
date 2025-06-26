/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:24:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/26 10:40:51 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	handle_error(int error_code)
{
	const char	*msg;

	if (error_code == 1)
		msg = "Archivo de mapa no encontrado";
	else if (error_code == 2)
		msg = "Mapa inválido";
	else if (error_code == 3)
		msg = "Error de memoria";
	else if (error_code == 4)
		msg = "Error al inicializar gráficos";
	else
		msg = "Error desconocido";
	ft_printf("Error: %s\n", msg);
	return (0);
}
