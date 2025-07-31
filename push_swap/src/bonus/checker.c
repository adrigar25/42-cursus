/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:09 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/31 12:34:43 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

char	**store_numbers(char **argv, int is_string)
{
	if (is_string)
		return (ft_split(argv[1], ' '));
	else
		return (&argv[1]);
}

void	print_result(int is_ok)
{
	if (is_ok)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**str_num;
	int		size;
	int		is_split;

	stack = NULL;
	size = 0;
	is_split = argc == 2;
	if (argc < 2)
		return (write(2, "Error\n", 7));
	str_num = store_numbers(argv, is_split);
	if (!valid_numbers(str_num))
	{
		if (is_split)
			free_split(str_num);
		return (write(2, "Error\n", 6));
	}
	while (str_num[size])
		size++;
	stack = fill_stack(str_num, size);
	execute_ops(&stack);
	print_result(is_sorted(stack) && stack_size(stack) == size);
	free_stack(stack);
	if (is_split)
		free_split(str_num);
	return (0);
}
