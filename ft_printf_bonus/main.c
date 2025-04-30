/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:33:53 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/30 16:34:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int ret;

    ret = ft_printf("Hello, %s!\n", "world");
    ft_printf("Return value: %d\n", ret);
    ret = ft_printf("Hex: %x\n", 255);
    ft_printf("Return value: %d\n", ret);
    ret = ft_printf("Pointer: %p\n", &ret);
    ft_printf("Return value: %d\n", ret);
    ret = ft_printf("Number: %d\n", -42);
    ft_printf("Return value: %d\n", ret);

    ret = ft_printf("hash: %#x\n", 255);
    ft_printf("Return value: %d\n", ret);
    ret = ft_printf("space: % d\n", 42);
    ft_printf("Return value: %d\n", ret);
    ret = ft_printf("plus: %+d\n", 42);
    ft_printf("Return value: %d\n", ret);
    return (0);
}