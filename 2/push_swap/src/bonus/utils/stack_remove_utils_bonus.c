/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:07:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/29 18:37:49 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	stack_remove_front(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

void	stack_remove_back(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack || !*stack)
		return ;
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	prev = NULL;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	free(tmp);
}
