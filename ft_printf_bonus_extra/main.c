#include "./bonus/ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("prueba c: %c\n", 'A');
	ft_printf("prueba s: %s\n", "Hola Mundo");
	ft_printf("prueba %%: %%\n");
	ft_printf("prueba d: %d\n", 42);
	ft_printf("prueba i: %i\n", -42);
	ft_printf("prueba u: %u\n", 42);
	ft_printf("prueba p: %p\n", (void *)0x12345678);
	ft_printf("prueba x: %x\n", 42);
	ft_printf("prueba X: %X\n", 42);
	ft_printf("prueba +: %+d\n", 42);
	ft_printf("prueba +: %+d\n", -42);
	ft_printf("prueba +: %+i\n", 42);
	ft_printf("prueba +: %+i\n", -42);
	ft_printf("prueba +: % d\n", 42);
	ft_printf("prueba +: % d\n", -42);
	ft_printf("prueba +: % i\n", 42);
	ft_printf("prueba +: % i\n", -42);
	ft_printf("prueba +: %#x\n", 42);
	ft_printf("prueba +: %#X\n", 42);

	printf("prueba c: %c\n", 'A');
	printf("prueba s: %s\n", "Hola Mundo");
	printf("prueba %%: %%\n");
	printf("prueba d: %d\n", 42);
	printf("prueba i: %i\n", -42);
	printf("prueba u: %u\n", 42);
	printf("prueba p: %p\n", (void *)0x12345678);
	printf("prueba x: %x\n", 42);
	printf("prueba X: %X\n", 42);
	printf("prueba +: %+d\n", 42);
	printf("prueba +: %+d\n", -42);
	printf("prueba +: %+i\n", 42);
	printf("prueba +: %+i\n", -42);
	printf("prueba +: % d\n", 42);
	printf("prueba +: % d\n", -42);
	printf("prueba +: % i\n", 42);
	printf("prueba +: % i\n", -42);
	printf("prueba +: %#x\n", 42);
	printf("prueba +: %#X\n", 42);
	printf("prueba +: %s\n", "hola");

	printf(" % 1s", "");
	printf("% 1s ", "");

	return (0);
}