#include "ft_printf_bonus.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    // Prueba de flags: +, espacio, #
    len1 = ft_printf("|%+d| |% d| |%#x| |%#X|\n", 42, 42, 42, 42);
    len2 = printf   ("|%+d| |% d| |%#x| |%#X|\n", 42, 42, 42, 42);

    ft_printf("ft_printf len: %d\n", len1);
    printf   ("printf    len: %d\n", len2);

    return 0;
}
