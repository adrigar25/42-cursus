/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:48:37 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/30 18:21:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../libs/get_next_line/get_next_line.h"
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

int					is_sorted(t_stack *stack);

// Checker utils

void				execute_op(t_stack **a, t_stack **b, const char *op);
void				execute_ops(t_stack **a);
char				**store_numbers(char **argv, int is_string);
#endif