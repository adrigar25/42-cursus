/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/05 11:55:19 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, int upper)
{
	char	*base;
	int		count = 0;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}
