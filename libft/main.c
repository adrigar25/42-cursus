#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_result(char *expected, char *actual)
{
	if (expected == NULL && actual == NULL)
	{
		printf("\033[0;32m[PASS]\033[0m\n");
		return ;
	}
	if (strcmp(expected, actual) == 0)
		printf("\033[0;32m[PASS]\033[0m\n");
	else
		printf("\033[0;31m[FAIL]\033[0m\n");
}

char	my_function(unsigned int i, char c)
{
	return (c + i);
}

void	my_function2(unsigned int i, char *c)
{
	if (*c >= 32 && *c <= 126) // Solo modifica caracteres imprimibles
		*c = (*c + i) % 127;  
			// Asegura que el resultado esté en el rango ASCII
	if (*c < 32)               // Si cae fuera del rango imprimible, ajusta
		*c += 32;
}

int	main(void)
{
	char	src[100] = "Hello World";
	char	*str;
	char	**result;

	// Pruebas para ft_striteri
	ft_striteri(src, my_function2);
	printf("ft_striteri: %s\n", src);
	printf("Expected: %s\n", "Hfnos!Xpsme");
	ft_result("Hfnos!Xpsme", src);
	// Pruebas para ft_split
	printf("\n\033[0;33mTesting ft_split:\033[0m\n");
	result = ft_split("Hello World", ' ');
	printf("ft_split: %s\n", result[0]);
	printf("Expected: %s\n", "Hello");
	ft_result("Hello", result[0]);
	// Pruebas para ft_strdup
	printf("\n\033[0;33mTesting ft_strdup:\033[0m\n");
	str = ft_strdup("Hello World");
	printf("ft_strdup: %s\n", str);
	printf("Expected: %s\n", "Hello World");
	ft_result("Hello World", str);
	// Pruebas para ft_substr
	printf("\n\033[0;33mTesting ft_substr:\033[0m\n");
	str = ft_substr("Hello World", 0, 5);
	printf("ft_substr: %s\n", str);
	printf("Expected: %s\n", "Hello");
	ft_result("Hello", str);
	// Pruebas para ft_strtrim
	printf("\n\033[0;33mTesting ft_strtrim:\033[0m\n");
	str = ft_strtrim("   Hello World   ", " ");
	printf("ft_strtrim: %s\n", str);
	printf("Expected: %s\n", "Hello World");
	ft_result("Hello World", str);
	// Pruebas para ft_strlcpy
	printf("\n\033[0;33mTesting ft_strlcpy:\033[0m\n");
	str = malloc(20);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	ft_strlcpy(str, "Hello World", 20);
	printf("ft_strlcpy: %s\n", str);
	printf("Expected: %s\n", "Hello World");
	ft_result("Hello World", str);
	return (0);
}
