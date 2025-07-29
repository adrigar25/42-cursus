/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:48:09 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/29 17:30:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libs/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Stack add & remove

void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_add_front(t_stack **stack, t_stack *new);
void				stack_remove_front(t_stack **stack);
void				stack_remove_front(t_stack **stack);

// Validación y parsing
int					is_valid_number(const char *str);
int					valid_numbers(char **numbers);
int					*parse_numbers(char **numbers, int size);

// Stack utils
t_stack				*fill_stack(char **str_num, int size);
void				assign_index(t_stack *stack);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);

// Algoritmos

// Small Sort
void				sort(t_stack **stack, int size);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);

// Big Sort
int					get_max_index(t_stack *stack);
void				push_chunk(t_stack **a, t_stack **b, int chunk_size);
int					get_pos(t_stack *stack, int index);
void				push_back_to_a(t_stack **a, t_stack **b);

// Operaciones
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				free_split(char **split);

#endif