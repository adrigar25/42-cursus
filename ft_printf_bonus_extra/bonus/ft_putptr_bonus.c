/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:24:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/09 20:27:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putptr(void *ptr)
{
	t_flags	flags;
	flags.hash = 1;
	if (!ptr)
		return (ft_putstr("0x0"));
	return (ft_puthex((unsigned long long)ptr, 0, flags));
}
