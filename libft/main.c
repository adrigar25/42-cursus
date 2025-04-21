#include "libft.h"
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

void *test_function_map(void *content)
{
	char *str = (char *)content;
	unsigned int i = 0;

	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			str[i] = (str[i] + i) % 127;
		if (str[i] < 32)
			str[i] += 32;
		i++;
	}
	return (content);
}

void	free_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*mapped_lst;

	printf("\n\033[0;33mTesting ft_lstmap:\033[0m\n");

	// Create the original list
	lst = ft_lstnew(strdup("Hello"));
	new_node = ft_lstnew(strdup("World"));
	ft_lstadd_back(&lst, new_node);

	// Apply ft_lstmap
	mapped_lst = ft_lstmap(lst, test_function_map, free_content);

	// Test the first node
	printf("ft_lstmap (first node): %s\n", (char *)mapped_lst->content);
	printf("Expected: %s\n", "Hello");
	ft_result("Hello", (char *)mapped_lst->content);

	// Test the second node
	printf("ft_lstmap (second node): %s\n", (char *)mapped_lst->next->content);
	printf("Expected: %s\n", "World");
	ft_result("World", (char *)mapped_lst->next->content);

	// Free allocated memory
	ft_lstclear(&lst, free_content);
	ft_lstclear(&mapped_lst, free_content);

	return (0);
}