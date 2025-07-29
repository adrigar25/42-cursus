/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:17:35 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/29 15:52:31 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*fill_stack(char **str_num, int size)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;
	int		*numbers;

	numbers = parse_numbers(str_num, size);
	stack = NULL;
	i = 0;
	while (i < size)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->number = numbers[i];
		new->index = 0;
		new->next = NULL;
		stack_add_back(&stack, new);
		i++;
	}
	free(numbers);
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	assign_index(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	tmp1 = stack;
	while (tmp1)
	{
		index = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1->number > tmp2->number)
				index++;
			tmp2 = tmp2->next;
		}
		tmp1->index = index;
		tmp1 = tmp1->next;
	}
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
