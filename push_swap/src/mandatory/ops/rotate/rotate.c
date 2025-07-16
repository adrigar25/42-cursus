/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:45:47 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/01 11:00:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	stack_add_back(stack, first);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	stack_add_front(stack, last);
}
