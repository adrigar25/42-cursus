/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:17:35 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/07 19:44:01 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*fill_stack(int *numbers, int count)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
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
