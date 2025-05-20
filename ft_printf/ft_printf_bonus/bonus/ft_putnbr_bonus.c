/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:45:58 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/10 01:19:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(int n, t_flags flags)
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
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10, (t_flags){0, 0, 0});
	return (count + ft_putchar((n % 10) + '0'));
}
