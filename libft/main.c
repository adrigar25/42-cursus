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
	return (c + i); // Ejemplo: suma el índice al valor ASCII del carácter
}

int	main(void)
{
	char	src[100] = "Hello World";
	char	**result;
	char	*itoa_result;
	char	*itoa_result_neg;
	char	*str;
	char	*strmapi_result;

	// Pruebas para ft_split
	printf("\n=== Pruebas para ft_split ===\n");
	result = ft_split(src, ' ');
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("ft_split: %s\n", result[i]);
		free(result[i]);
	}
	free(result);
	// Pruebas para ft_itoa
	printf("\n=== Pruebas para ft_itoa ===\n");
	itoa_result = ft_itoa(42);
	itoa_result_neg = ft_itoa(-42);
	printf("ft_itoa(42): %s\n", itoa_result);
	printf("ft_itoa(-42): %s\n", itoa_result_neg);
	free(itoa_result);
	free(itoa_result_neg);
	// Pruebas para ft_strmapi
	printf("\n=== Pruebas para ft_strmapi ===\n");
	str = "Hello";
	strmapi_result = ft_strmapi(str, my_function);
	printf("ft_strmapi: %s\n", strmapi_result);
	free(strmapi_result);
	return (0);
}
