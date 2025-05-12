/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:18:18 by agarcia           #+#    #+#             */
/*   Updated: 2025/05/12 19:57:52 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_format(char format, va_list *args, t_flags flags)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int), flags));
	if (format == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), format == 'X', flags));
	return (0);
}

t_flags	handle_flags(const char **format, t_flags flags)
{
	while (**format == ' ' || **format == '+' || **format == '#')
	{
		if (**format == ' ')
			flags.space = 1;
		if (**format == '+')
			flags.plus = 1;
		if (**format == '#')
			flags.hash = 1;
		(*format)++;
	}
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;
	va_list	args;
	int		count;

	count = 0;
	flags = (t_flags){0, 0, 0};
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			flags = handle_flags(&format, flags);
			if (*format >= '0' && *format <= '9')
			{
				count += ft_putchar(' ');
				format++;
			}
			count += handle_format(*format, &args, flags);
			flags = (t_flags){0, 0, 0};
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
