/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:10 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/17 23:22:06 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_number(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	printf("\nstack:");
	while (stack)
	{
		write(1, &((char[12]){0}), 0);
		printf("%d%s", stack->number, (!stack->next
				|| !stack->next->number) ? "" : ", ");
		stack = stack->next;
	}
}
int	valid_numbers(char **numbers)
{
	int	j;

	j = 0;
	if (!numbers || !*numbers)
		return (0);
	while (numbers[j])
	{
		if (!is_number(numbers[j]))
			return (0);
		j++;
	}
	return (1);
}

int	*parse_numbers(char **numbers, int *size)
{
	int	*arr;
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	*size = i;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (numbers[i])
	{
		arr[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**numbers;
	int		*int_arr;
	int		size;

	stack = NULL;
	numbers = NULL;
	int_arr = NULL;
	size = 0;
	if (argc < 2)
	{
		write(2, "Error0\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers || !*numbers)
		{
			write(2, "Error1\n", 6);
			return (1);
		}
	}
	else
		numbers = &argv[1];
	if (!valid_numbers(numbers))
	{
		write(2, "Error2\n", 6);
		return (1);
	}
	int_arr = parse_numbers(numbers, &size);
	stack = fill_stack(int_arr, size);
	// printf("antes: ");
	print_stack(stack);
	k_sort(&stack, size);
	// printf("\ndespues: ");
	print_stack(stack);
	free_stack(stack);
	free(int_arr);
	return (0);
}
