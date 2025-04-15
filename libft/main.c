#include "libft.h"
#include <bsd/string.h>
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

int	main(void)
{
	char	src[100] = "Hello World";
	char	dest_memset[100];
	char	dest2_memset[100];
	char	dest_bzero[100] = "hola";
	char	dest2_bzero[100] = "hola";
	char	dest_memcpy[100];
	char	dest2_memcpy[100];
	char	src1[] = "Hola Mundo";
	char	dest1[100];
	char	dest2[100];
	char	src2_ft[100] = "Solapamiento hacia adelante";
	char	src2_mem[100] = "Solapamiento hacia adelante";
	char	src3_ft[100] = "Solapamiento hacia atrás";
	char	src3_mem[100] = "Solapamiento hacia atrás";
	char	src4_ft[100] = "1234567890";
	char	src4_mem[100] = "1234567890";
	char	src_strlcpy[] = "Hello, 42!";
	char	dest_ft[20];
	char	dest_std[20];
	char	dest_strlcat[100] = "Hola ";
	char	dest2_strlcat[100] = "Hola ";
	char	src_strlcat[] = "Mundo!";

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
	printf("ft_isdigit('\\0'): %d | isdigit('\\0'): %d\n", ft_isdigit('\0'),
		isdigit('\0'));
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
	printf("ft_strlen(\"%s\"): %ld | strlen(\"%s\"): %lu\n", src, ft_strlen(src),
		src, strlen(src));
	printf("\n");
	// Pruebas para ft_memset vs memset
	printf("=== Pruebas para ft_memset vs memset ===\n");
	ft_memset(dest_memset, '*', 10);
	dest_memset[10] = '\0';
	memset(dest2_memset, '*', 10);
	dest2_memset[10] = '\0';
	printf("ft_memset: %s | memset: %s\n", dest_memset, dest2_memset);
	ft_result(dest_memset, dest2_memset);
	printf("\n");
	// Pruebas para ft_bzero vs bzero
	printf("=== Pruebas para ft_bzero vs bzero ===\n");
	ft_bzero(&dest_bzero[3], 10);
	bzero(&dest2_bzero[3], 10);
	printf("ft_bzero: %s | bzero: %s\n", dest_bzero, dest2_bzero);
	ft_result(dest_bzero, dest2_bzero);
	printf("\n");
	// Pruebas para ft_memcpy vs memcpy
	printf("=== Pruebas para ft_memcpy vs memcpy ===\n");
	ft_memcpy(dest_memcpy, src, 5);
	memcpy(dest2_memcpy, src, 5);
	dest_memcpy[5] = '\0';  // Agregar el carácter nulo
	dest2_memcpy[5] = '\0'; // Agregar el carácter nulo
	printf("ft_memcpy: %s | memcpy: %s\n", dest_memcpy, dest2_memcpy);
	ft_result(dest_memcpy, dest2_memcpy);
	printf("\n");
	// Pruebas para ft_memmove vs memmove
	printf("=== Prueba para ft_memmove vs memmove ===\n");
	// Caso 1: Sin solapamiento
	ft_memmove(dest1, src1, 5);
	memmove(dest2, src1, 5);
	dest1[5] = '\0';
	dest2[5] = '\0';
	printf("Sin solapamiento:\n");
	printf("ft_memmove: %s | memmove: %s\n", dest1, dest2);
	ft_result(dest1, dest2);
	// Caso 2: Solapamiento hacia adelante
	ft_memmove(src2_ft + 5, src2_ft, 10);
	memmove(src2_mem + 5, src2_mem, 10);
	printf("\nSolapamiento hacia adelante:\n");
	printf("ft_memmove: %s\n", src2_ft);
	printf("memmove: %s\n", src2_mem);
	ft_result(src2_ft, src2_mem);
	// Caso 3: Solapamiento hacia atrás
	ft_memmove(src3_ft, src3_ft + 5, 10);
	memmove(src3_mem, src3_mem + 5, 10);
	printf("\nSolapamiento hacia atrás:\n");
	printf("ft_memmove: %s\n", src3_ft);
	printf("memmove: %s\n", src3_mem);
	ft_result(src3_ft, src3_mem);
	// Caso 4: Copia completa dentro del mismo buffer
	ft_memmove(src4_ft + 2, src4_ft, 8);
	memmove(src4_mem + 2, src4_mem, 8);
	printf("\nCopia completa dentro del mismo buffer:\n");
	printf("ft_memmove: %s\n", src4_ft);
	printf("memmove: %s\n", src4_mem);
	ft_result(src4_ft, src4_mem);
	// Pruebas para ft_strlcpy vs strlcpy
	printf("\n=== Pruebas para ft_strlcpy vs strlcpy ===\n");
	size_t ret_ft, ret_std;
	// Caso 1: Copia completa con espacio suficiente
	ret_ft = ft_strlcpy(dest_ft, src_strlcpy, sizeof(dest_ft));
	ret_std = strlcpy(dest_std, src_strlcpy, sizeof(dest_std));
	printf("Caso 1: Copia completa con espacio suficiente\n");
	printf("ft_strlcpy: %s (ret: %zu) | strlcpy: %s (ret: %zu)\n", dest_ft,
		ret_ft, dest_std, ret_std);
	ft_result(dest_ft, dest_std);
	// Caso 2: Copia truncada
	ret_ft = ft_strlcpy(dest_ft, src_strlcpy, 6);
	ret_std = strlcpy(dest_std, src_strlcpy, 6);
	printf("\nCaso 2: Copia truncada\n");
	printf("ft_strlcpy: %s (ret: %zu) | strlcpy: %s (ret: %zu)\n", dest_ft,
		ret_ft, dest_std, ret_std);
	ft_result(dest_ft, dest_std);
	// Caso 3: dstsize es 0
	ret_ft = ft_strlcpy(dest_ft, src_strlcpy, 0);
	ret_std = strlcpy(dest_std, src_strlcpy, 0);
	printf("\nCaso 3: dstsize es 0\n");
	printf("ft_strlcpy: %s (ret: %zu) | strlcpy: %s (ret: %zu)\n", dest_ft,
		ret_ft, dest_std, ret_std);
	ft_result(dest_ft, dest_std);
	// Caso 4: src es una cadena vacía
	ret_ft = ft_strlcpy(dest_ft, "", sizeof(dest_ft));
	ret_std = strlcpy(dest_std, "", sizeof(dest_std));
	printf("\nCaso 4: src es una cadena vacía\n");
	printf("ft_strlcpy: %s (ret: %zu) | strlcpy: %s (ret: %zu)\n", dest_ft,
		ret_ft, dest_std, ret_std);
	ft_result(dest_ft, dest_std);
	// Pruebas para ft_strlcat vs strlcat
	printf("\n=== Pruebas para ft_strlcat vs strlcat ===\n");
	size_t ret_ft_strlcat, ret_std_strlcat;
	// Caso 1: Concatenación completa con espacio suficiente
	ret_ft_strlcat = ft_strlcat(dest_strlcat, src_strlcat,
			sizeof(dest_strlcat));
	ret_std_strlcat = strlcat(dest2_strlcat, src_strlcat,
			sizeof(dest2_strlcat));
	printf("Caso 1: Concatenación completa con espacio suficiente\n");
	printf("ft_strlcat: %s (ret: %zu) | strlcat: %s (ret: %zu)\n", dest_strlcat,
		ret_ft_strlcat, dest2_strlcat, ret_std_strlcat);
	ft_result(dest_strlcat, dest2_strlcat);
	// Caso 2: Concatenación truncada
	ret_ft_strlcat = ft_strlcat(dest_strlcat, src_strlcat, 10);
	ret_std_strlcat = strlcat(dest2_strlcat, src_strlcat, 10);
	printf("\nCaso 2: Concatenación truncada\n");
	printf("ft_strlcat: %s (ret: %zu) | strlcat: %s (ret: %zu)\n", dest_strlcat,
		ret_ft_strlcat, dest2_strlcat, ret_std_strlcat);
	ft_result(dest_strlcat, dest2_strlcat);
	// Caso 3: dstsize es 0
	ret_ft_strlcat = ft_strlcat(dest_strlcat, src_strlcat, 0);
	ret_std_strlcat = strlcat(dest2_strlcat, src_strlcat, 0);
	printf("\nCaso 3: dstsize es 0\n");
	printf("ft_strlcat: %s (ret: %zu) | strlcat: %s (ret: %zu)\n", dest_strlcat,
		ret_ft_strlcat, dest2_strlcat, ret_std_strlcat);
	ft_result(dest_strlcat, dest2_strlcat);
	// Pruebas para ft_toupper vs toupper
	printf("\n=== Pruebas para ft_toupper vs toupper ===\n");
	printf("ft_toupper('a'): %c | toupper('a'): %c\n", ft_toupper('a'),
		toupper('a'));
	printf("ft_toupper('A'): %c | toupper('A'): %c\n", ft_toupper('A'),
		toupper('A'));
	printf("ft_toupper('1'): %c | toupper('1'): %c\n", ft_toupper('1'),
		toupper('1'));
	// Pruebas para ft_tolower vs tolower
	printf("\n=== Pruebas para ft_tolower vs tolower ===\n");
	printf("ft_tolower('a'): %c | tolower('a'): %c\n", ft_tolower('a'),
		tolower('a'));
	printf("ft_tolower('A'): %c | tolower('A'): %c\n", ft_tolower('A'),
		tolower('A'));
	printf("ft_tolower('1'): %c | tolower('1'): %c\n", ft_tolower('1'),
		tolower('1'));
	// Pruebas para ft_strchr vs strchr
	printf("\n=== Pruebas para ft_strchr vs strchr ===\n");
	printf("ft_strchr(\"%s\", 'o'): %s | strchr(\"%s\", 'o'): %s\n", src,
		ft_strchr(src, 'o'), src, strchr(src, 'o'));
	ft_result(ft_strchr(src, 'o'), strchr(src, 'o'));
	printf("ft_strchr(\"%s\", 'z'): %s | strchr(\"%s\", 'z'): %s\n", src,
		ft_strchr(src, 'z'), src, strchr(src, 'z'));
	ft_result(ft_strchr(src, 'z'), strchr(src, 'z'));
	printf("ft_strchr(\"%s\", '\\0'): %s | strchr(\"%s\", '\\0'): %s\n", src,
		ft_strchr(src, '\0'), src, strchr(src, '\0'));
	ft_result(ft_strchr(src, '\0'), strchr(src, '\0'));
	printf("\n");
	// Pruebas para ft_strrchr vs strrchr
	printf("=== Pruebas para ft_strrchr vs strrchr ===\n");
	printf("ft_strrchr(\"%s\", 'o'): %s | strrchr(\"%s\", 'o'): %s\n", src,
		ft_strrchr(src, 'o'), src, strrchr(src, 'o'));
	ft_result(ft_strrchr(src, 'o'), strrchr(src, 'o'));
	printf("ft_strrchr(\"%s\", 'z'): %s | strrchr(\"%s\", 'z'): %s\n", src,
		ft_strrchr(src, 'z'), src, strrchr(src, 'z'));
	ft_result(ft_strrchr(src, 'z'), strrchr(src, 'z'));
	printf("ft_strrchr(\"%s\", '\\0'): %s | strrchr(\"%s\", '\\0'): %s\n", src,
		ft_strrchr(src, '\0'), src, strrchr(src, '\0'));
	ft_result(ft_strrchr(src, '\0'), strrchr(src, '\0'));
	// Pruebas para ft_strncmp vs strncmp
	printf("\n=== Pruebas para ft_strncmp vs strncmp ===\n");
	printf("ft_strncmp(\"%s\", \"%s\", 5): %d | strncmp(\"%s\", \"%s\", 5):%d\n", src, src1, ft_strncmp(src, src1, 5), src, src1, strncmp(src,
			src1, 5));
	if (ft_strncmp("abc", "abc", 7) == strncmp("abc", "abc", 7))
		printf("\033[0;32m[PASS]\033[0m\n");
	else
		printf("\033[0;31m[FAIL]\033[0m\n");
	printf("ft_strncmp(\"%s\", \"%s\", 5): %d | strncmp(\"%s\", \"%s\", 5):%d\n", src, src, ft_strncmp(src, src, 5), src, src, strncmp(src, src,
			5));
	if (ft_strncmp(src, src, 5) == strncmp(src, src, 5))
		printf("\033[0;32m[PASS]\033[0m\n");
	else
		printf("\033[0;31m[FAIL]\033[0m\n");
	// Pruebas para ft_memchr vs memchr
	printf("\n=== Pruebas para ft_memchr vs memchr ===\n");
	printf("ft_memchr(\"%s\", 'o', 5): %s | memchr(\"%s\", 'o', 5): %s\n", src,
		(unsigned char *)ft_memchr(src, 'o', 2), src,
		(unsigned char *)memchr(src, 'o', 2));
	ft_result((char *)ft_memchr(src, 'o', 2), (char *)memchr(src, 'o', 2));
	// Pruebas para ft_memcmp vs memcmp
	printf("\n=== Pruebas para ft_memcmp vs memcmp ===\n");
	printf("ft_memcmp(\"%s\", \"%s\", 5): %d | memcmp(\"%s\", \"%s\", 5): %d\n",
		src, src1, ft_memcmp(src, src1, 5), src, src1, memcmp(src, src1, 5));
	if (ft_memcmp(src, src1, 5) == memcmp(src, src1, 5))
		printf("\033[0;32m[PASS]\033[0m\n");
	else
		printf("\033[0;31m[FAIL]\033[0m\n");
	// Pruebas para ft_strnstr vs strnstr
	printf("\n=== Pruebas para ft_strnstr vs strnstr ===\n");
	printf("ft_strnstr(\"%s\", \"\\0\", 10): %s | strnstr(\"%s\", \"\\0\", 10): %s\n", src, ft_strnstr(src, "\0", 4), src, strnstr(src, "\0", 4));
	ft_result(ft_strnstr(src, "Hello", 4), strnstr(src, "Hello", 4));
	// Pruebas para ft_atoi vs atoi
	printf("\n=== Pruebas para ft_atoi vs atoi ===\n");
	printf("ft_atoi(\"%s\"): %d | atoi(\"%s\"): %d\n", "    42",
		ft_atoi("    42"), "    42", atoi("    42"));
	if (ft_atoi(src) == atoi(src))
		printf("\033[0;32m[PASS]\033[0m\n");
	else
		printf("\033[0;31m[FAIL]\033[0m\n");
	// Pruebas para ft_calloc vs calloc
	printf("\n=== Pruebas para ft_calloc vs calloc ===\n");
	printf("ft_calloc(5, 4): ");
	int *ft_calloc_array = ft_calloc(5, 4);
	for (int i = 0; i < 5; i++) {
		printf("%d ", ft_calloc_array[i]);
	}
	printf("| calloc(5, 4): ");
	int *calloc_array = calloc(5, 4);
	for (int i = 0; i < 5; i++) {
		printf("%d ", calloc_array[i]);
	}
	printf("\n");

	// Pruebas para ft_strdup vs strdup
	printf("\n=== Pruebas para ft_strdup vs strdup ===\n");
	char *ft_strdup_result = ft_strdup(src);
	char *strdup_result = strdup(src);
	printf("ft_strdup: %s | strdup: %s\n", ft_strdup_result, strdup_result);
	ft_result(ft_strdup_result, strdup_result);

	//Pruebas para ft_substr
	printf("\n=== Pruebas para ft_substr ===\n");
	printf("ft_substr(\"%s\", 0, 5): %s\n", src, ft_substr(src, 0, 5));

	//Pruebas para ft_strjoin
	printf("\n=== Pruebas para ft_strjoin ===\n");
	printf("ft_strjoin(\"%s\", \"%s\"): %s\n", src, src1,
		ft_strjoin(src, src1));

	//Pruebas para ft_strtrim
	printf("\n=== Pruebas para ft_strtrim ===\n");
	printf("ft_strtrim(\"%s\", \"H\"): %s\n", src, ft_strtrim(src, "H"));
	return (0);
}
