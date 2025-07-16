#include "push_swap.h"

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

int	*sort_array(const int *arr, int size)
{
	int	*sorted;
	int	temp;
	int	i;
	int	j;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

int	calculate_k(int *arr, int *sorted, int size)
{
	int	k;
	int	dist;
	int	j;
	int	i;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				dist = abs(i - j);
				if (dist > k)
					k = dist;
				break ;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*ptr1;
	int		index;
	t_stack	*ptr2;

	ptr1 = stack;
	while (ptr1)
	{
		index = 0;
		ptr2 = stack;
		while (ptr2)
		{
			if (ptr2->number < ptr1->number)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}

int	stack_has_in_chunk(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	get_closest_chunk_pos(t_stack *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	push_chunk(t_stack **a, t_stack **b, int min_index, int max_index)
{
	int	pos;
	int	size;
	int	mid;

	size = stack_size(*a);
	mid = (min_index + max_index) / 2;
	while (stack_has_in_chunk(*a, min_index, max_index))
	{
		pos = get_closest_chunk_pos(*a, min_index, max_index);
		if (pos <= size / 2)
		{
			while ((*a)->index < min_index || (*a)->index > max_index)
				ra(a);
		}
		else
		{
			while ((*a)->index < min_index || (*a)->index > max_index)
				rra(a);
		}
		// Estrategia: si es menor que el centro del chunk, haz rb
		if ((*a)->index <= mid)
		{
			pb(a, b);
			rb(b);
		}
		else
		{
			pb(a, b);
		}
	}
}

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		max_index = get_max_index(*b);
		pos = get_position(*b, max_index);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rb(b);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b);
		}
		pa(b, a);
	}
}

void	k_sort(t_stack **a, int size)
{
	t_stack	*b;
	int		arr[size];
	t_stack	*tmp;
	int		*sorted;
	int		k;
	int		chunk_count;
	int		chunk_size;
	int		min_index;
	int		max_index;

	b = NULL;
	assign_indexes(*a);
	tmp = *a;
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp->number;
		tmp = tmp->next;
	}
	sorted = sort_array(arr, size);
	k = calculate_k(arr, sorted, size);
	free(sorted);
	if (k <= 5)
		chunk_count = 3;
	else if (k <= 15)
		chunk_count = 4;
	else if (k <= 30)
		chunk_count = 5;
	else
		chunk_count = 6;
	chunk_size = size / chunk_count;
	min_index = 0;
	max_index = chunk_size - 1;
	while (min_index < size)
	{
		push_chunk(a, &b, min_index, max_index);
		min_index += chunk_size;
		max_index += chunk_size;
	}
	push_back_to_a(a, &b);
}
