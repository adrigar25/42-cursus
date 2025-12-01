/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:09 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/31 15:01:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	execute_op(t_stack **a, t_stack **b, const char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	execute_ops(t_stack **a)
{
	t_stack	*b;
	char	*op;

	b = NULL;
	op = get_next_line(0);
	while (op)
	{
		if (!execute_op(a, &b, op))
		{
			free(op);
			write(2, "Error\n", 6);
			return (0);
		}
		free(op);
		op = get_next_line(0);
	}
	return (1);
}
