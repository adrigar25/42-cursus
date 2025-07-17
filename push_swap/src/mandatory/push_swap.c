#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
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
void	k_sort(t_stack **a, int size)
{
	t_stack	*b;

	b = NULL;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
}
