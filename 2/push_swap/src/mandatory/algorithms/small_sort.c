/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:04:33 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/30 14:26:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_stack *a)
{
	int		min;
	int		index;
	int		min_index;
	t_stack	*current;

	if (!a)
		return (-1);
	min = a->number;
	min_index = 0;
	index = 0;
	current = a;
	while (current)
	{
		if (current->number < min)
		{
			min = current->number;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	sort_2(t_stack **a)

{
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->number;
	n2 = (*a)->next->number;
	n3 = (*a)->next->next->number;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	while (min_index > 0)
	{
		ra(a);
		min_index--;
	}
	pb(a, b);
	sort_3(a);
	pa(b, a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	while (min_index-- > 0)
		ra(a);
	pb(a, b);
	min_index = find_min_index(*a);
	if (min_index <= 4 / 2)
		while (min_index-- > 0)
			ra(a);
	else
		while (min_index++ < 4)
			rra(a);
	pb(a, b);
	sort_3(a);
	pa(b, a);
	pa(b, a);
}
