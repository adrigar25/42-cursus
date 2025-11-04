/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:51:51 by agarcia           #+#    #+#             */
/*   Updated: 2025/06/05 11:59:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned long long n, int upper);
int		ft_putptr(void *ptr);

int		handler_hex(unsigned long long n, int upper, t_flags flags);
int		handler_nbr(int n, t_flags flags);

#endif