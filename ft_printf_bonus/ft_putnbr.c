/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:45:58 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/30 16:38:26 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (flags.space && n >= 0)
	{
		count += ft_putchar(' ');
		flags.space = 0;
	}
	if (flags.plus && n >= 0)
	{
		count += ft_putchar('+');
		flags.plus = 0;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10, flags);
	return (count + ft_putchar((n % 10) + '0'));
}
