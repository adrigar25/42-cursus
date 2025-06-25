/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:45:58 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/05 12:00:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler_nbr(int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.plus == 1 && n >= 0)
	{
		count += ft_putchar('+');
		flags = (t_flags){0, 0, 0};
	}
	else if (flags.space == 1 && n >= 0)
	{
		count += ft_putchar(' ');
		flags = (t_flags){0, 0, 0};
	}
	count += ft_putnbr(n);
	return (count);
}
