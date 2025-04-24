/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:18:18 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/24 16:27:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	ft_print_arg(va_arg args, char arg_type)
{
    char *str;
	int	writen_chars;

	writen_chars = 0;
    if(arg_type == '%')
        writen_chars += write(1, '%', 1);
	if (arg_typ == 'c')
		writen_chars += write(1, va_arg(args, char), 1);
	if (arg_typ = 's')
    {
        str = va_arg(args, char *);
        while(str)
        {
            writen_chars += write(1, str, 1);
            str++
        }
    }
	return (writen_chars);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
    unsigned int    writen_chars;

    writen_chars = 0;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
        if(format[i] == '%')
            writen_chars += ft_print_arg(args, formart[i++]);
		i++;
	}
	return (writen_chars);
}

int	main(void)
{
	ft_printf("Hello, World!\n");
	return (0);
}