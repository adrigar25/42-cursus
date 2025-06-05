#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    // Prueba de enteros
    len1 = ft_printf("ft: |%d| |%i| |%u|\n", 42, -42, 4294967295u);
    len2 = printf   ("og: |%d| |%i| |%u|\n", 42, -42, 4294967295u);

    // Prueba de caracteres y strings
    ft_printf("ft: |%c| |%s|\n", 'A', "Hola mundo");
    printf   ("og: |%c| |%s|\n", 'A', "Hola mundo");

    // Prueba de punteros
    int x = 42;
    ft_printf("ft: |%p|\n", &x);
    printf   ("og: |%p|\n", &x);

    // Prueba de hexadecimal
    ft_printf("ft: |%x| |%X|\n", 255, 255);
    printf   ("og: |%x| |%X|\n", 255, 255);

    // Prueba de %%
    ft_printf("ft: 100%% real\n");
    printf   ("og: 100%% real\n");

    // Prueba de NULL string y puntero
    ft_printf("ft: |%s| |%p|\n", (char *)NULL, NULL);
    printf   ("og: |%s| |%p|\n", (char *)NULL, NULL);

    // Prueba de longitud
    ft_printf("ft_printf len: %d\n", len1);
    printf   ("printf    len: %d\n", len2);

    return 0;
}
