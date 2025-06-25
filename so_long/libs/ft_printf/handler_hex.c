/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/07 16:27:28 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler_hex(unsigned long long n, int upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.plus)
		flags.plus = 0;
	if (flags.hash && n != 0)
	{
		if (upper)
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
		flags.hash = 0;
	}
	count += ft_puthex(n, upper);
	return (count);
}
