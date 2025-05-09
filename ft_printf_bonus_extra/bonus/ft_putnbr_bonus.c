/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:45:58 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/09 21:58:19 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h> // Para printf de depuración

int	ft_putnbr(int n, t_flags flags)
{
    t_flags    temp_flags;
	int	count;

	count = 0;
    temp_flags.hash = 0;
    temp_flags.space = 0;
    temp_flags.plus = 0;
	// printf("flags.space: %d\n", flags.space);
	// printf("flags.plus: %d\n", flags.plus);
	// printf("flags.hash: %d\n", flags.hash);
	if (flags.plus == 1 && n >= 0)
	{
		count += ft_putchar('+');
		flags.space = 0;
		flags.plus = 0;
	}
	else if (flags.space == 1 && n >= 0)
	{
		count += ft_putchar(' ');
		flags.space = 0;
        flags.plus = 0;
	}
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10, temp_flags);
	return (count + ft_putchar((n % 10) + '0'));
}
