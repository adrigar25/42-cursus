/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:51:51 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/22 16:25:48 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
}		t_flags;

int		ft_printf(char const *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n, t_flags flags);
int		ft_putunbr(unsigned int n, t_flags flags);
int		ft_puthex(unsigned long long n, int upper, t_flags flags);
int		ft_putptr(void *ptr);

#endif