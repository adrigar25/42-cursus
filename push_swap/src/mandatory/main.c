/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:10 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/31 15:02:47 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort(t_stack **a, int size)
{
	t_stack	*b;
	int		chunk_size;

	if (is_sorted(*a))
		return ;
	assign_index(*a);
	b = NULL;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, &b);
	else if (size == 5)
		sort_5(a, &b);
	else if (size > 5)
	{
		chunk_size = 15 + (size > 100) * 15;
		push_chunk(a, &b, chunk_size);
		push_back_to_a(a, &b);
	}
}

char	**store_numbers(char **argv, int is_string)
{
	if (is_string)
		return (ft_split(argv[1], ' '));
	else
		return (&argv[1]);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**str_num;
	int		size;
	int		is_split;

	stack = NULL;
	str_num = NULL;
	size = 0;
	is_split = argc == 2;
	if (argc < 2)
		return (0);
	str_num = store_numbers(argv, is_split);
	if (valid_numbers(str_num))
	{
		while (str_num[size])
			size++;
		stack = fill_stack(str_num, size);
		sort(&stack, size);
	}
	else
		write(2, "Error\n", 6);
	free_stack(stack);
	if (is_split)
		free_split(str_num);
	return (0);
}
