/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:24:39 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/29 19:31:02 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putptr(void *ptr)
{
	t_flags	flags;

	flags.hash = 1;
	if (!ptr)
		return (ft_putstr("(nil)"));
	return (ft_puthex((unsigned long long)ptr, 0, flags));
}
