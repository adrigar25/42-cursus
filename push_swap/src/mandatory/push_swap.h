/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:09 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/17 00:12:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libs/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cost
{
	int cost_a; // movimientos en A (ra/rra)
	int cost_b; // movimientos en B (rb/rrb)
	int total;  // cost_a + cost_b ajustado para operaciones combinadas
	int dir_a;  // 1 = ra, -1 = rra
	int dir_b;  // 1 = rb, -1 = rrb
	int index;  // índice del número en B que vamos a mover
}					t_cost;

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					*sort_array(const int *arr, int size);
void				k_sort(t_stack **stack, int k);
int					calculate_k(int *arr, int *sorted, int size);
int					is_sorted(t_stack *stack);

// Stack utility functions
void				stack_add_front(t_stack **stack, t_stack *new);
void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_remove_front(t_stack **stack);
void				stack_remove_back(t_stack **stack);
t_stack				*fill_stack(int *number, int count);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack);

// Stack operations
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				swap(t_stack **stack);
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

#endif