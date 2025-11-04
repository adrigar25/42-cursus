/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:45:03 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/28 10:53:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_chunk(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

int	get_pos(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;

	while (*b)
	{
		max_index = get_max_index(*b);
		pos = get_pos(*b, max_index);
		if (pos <= stack_size(*b) / 2)
			while ((*b)->index != max_index)
				rb(b);
		else
			while ((*b)->index != max_index)
				rrb(b);
		pa(b, a);
	}
}
