/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:15:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/09 19:37:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putunbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	return (count + ft_putchar((n % 10) + '0'));
}
