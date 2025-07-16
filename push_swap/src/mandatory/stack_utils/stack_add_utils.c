/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:07:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/07 16:38:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}