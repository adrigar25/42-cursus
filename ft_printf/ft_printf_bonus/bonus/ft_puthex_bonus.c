/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/22 16:24:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthex(unsigned long long n, int upper, t_flags flags)
{
	char	*base;
	int		count;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
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
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, upper, flags);
	return (count + ft_putchar(base[n % 16]));
}
