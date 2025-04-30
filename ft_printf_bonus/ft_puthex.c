/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/30 16:37:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, int upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash && n != 0)
	{
		if (upper)
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");

		flags.hash = 0;
	}
	if (n >= 16)
		count += ft_puthex(n / 16, upper, flags);
	return (count
		+ ft_putchar((upper ? "0123456789ABCDEF" : "0123456789abcdef")[n
			% 16]));
}
