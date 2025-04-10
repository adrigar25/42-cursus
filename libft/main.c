#include "libft.h" // Para tus funciones
#include <ctype.h> // Para las funciones originales
#include <stdio.h>

int	main(void)
{
	// Pruebas para ft_isalpha vs isalpha
	printf("=== Pruebas para ft_isalpha vs isalpha ===\n");
	printf("ft_isalpha('A'): %d | isalpha('A'): %d\n", ft_isalpha('A'),
		isalpha('A'));
	printf("ft_isalpha('1'): %d | isalpha('1'): %d\n", ft_isalpha('1'),
		isalpha('1'));
	printf("ft_isalpha('$'): %d | isalpha('$'): %d\n", ft_isalpha('$'),
		isalpha('$'));
	printf("\n");

	// Pruebas para ft_isdigit vs isdigit
	printf("=== Pruebas para ft_isdigit vs isdigit ===\n");
	printf("ft_isdigit('5'): %d | isdigit('5'): %d\n", ft_isdigit('5'),
		isdigit('5'));
	printf("ft_isdigit('A'): %d | isdigit('A'): %d\n", ft_isdigit('A'),
		isdigit('A'));
	printf("ft_isdigit('#'): %d | isdigit('#'): %d\n", ft_isdigit('#'),
		isdigit('#'));
	printf("\n");

	// Pruebas para ft_isalnum vs isalnum
	printf("=== Pruebas para ft_isalnum vs isalnum ===\n");
	printf("ft_isalnum('B'): %d | isalnum('B'): %d\n", ft_isalnum('B'),
		isalnum('B'));
	printf("ft_isalnum('3'): %d | isalnum('3'): %d\n", ft_isalnum('3'),
		isalnum('3'));
	printf("ft_isalnum('*'): %d | isalnum('*'): %d\n", ft_isalnum('*'),
		isalnum('*'));
	printf("\n");

	// Pruebas para ft_isascii vs isascii
	printf("=== Pruebas para ft_isascii vs isascii ===\n");
	printf("ft_isascii(65): %d | isascii(65): %d\n", ft_isascii(65),
		isascii(65));
	printf("ft_isascii(128): %d | isascii(128): %d\n", ft_isascii(128),
		isascii(128));
	printf("ft_isascii(33): %d | isascii(33): %d\n", ft_isascii(33),
		isascii(33));
	printf("\n");

	// Pruebas para ft_isprint vs isprint
	printf("=== Pruebas para ft_isprint vs isprint ===\n");
	printf("ft_isprint(32): %d | isprint(32): %d\n", ft_isprint(32),
		isprint(32));
	printf("ft_isprint(127): %d | isprint(127): %d\n", ft_isprint(127),
		isprint(127));
	printf("ft_isprint(65): %d | isprint(65): %d\n", ft_isprint(65),
		isprint(65));
	printf("\n");

	// Pruebas para ft_strlen vs strlen
	printf("=== Pruebas para ft_strlen vs strlen ===\n");
	char str[] = "Hello, world!";
	printf("ft_strlen(\"%s\"): %d | strlen(\"%s\"): %lu\n", str, ft_strlen(str),
		str, strlen(str));
	printf("\n");

	// Pruebas para ft_memset vs memset
	printf("=== Pruebas para ft_memset vs memset ===\n");
	char buffer1[11]; // Espacio para 10 caracteres + '\0'
	char buffer2[11]; // Espacio para 10 caracteres + '\0'

	ft_memset(buffer1, '*', 10);
	buffer1[10] = '\0'; // Agregar el carácter nulo

	memset(buffer2, '*', 10);
	buffer2[10] = '\0'; // Agregar el carácter nulo

	printf("ft_memset: %s | memset: %s\n", buffer1, buffer2);
	printf("\n");

	// Pruebas para ft_bzero vs bzero
	printf("=== Pruebas para ft_bzero vs bzero ===\n");
	ft_bzero(buffer1, 10);
	bzero(buffer2, 10);
	printf("ft_bzero: %s | bzero: %s\n", buffer1, buffer2);
	printf("\n");

	return (0);
}