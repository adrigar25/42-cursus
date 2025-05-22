/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:15:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/22 16:24:30 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putunbr(unsigned int n, t_flags flags)
{
	int count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10, flags);
	return (count + ft_putchar((n % 10) + '0'));
}
