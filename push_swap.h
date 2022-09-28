/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:07:10 by malord            #+#    #+#             */
/*   Updated: 2022/09/28 10:00:10 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacklist {
	int					nb;
	int					index;
	int					position;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stacklist	*next;
}		t_stack;

// Error checking functions

void	check_doubles(t_stack *stack_a);
void	check_errors(char **argv, int index);
void	check_limits(char **array, int position, int calloc_flag);
void	check_numbers(char **argv, int index, int calloc_flag);
void	check_split(char **argv, t_stack **stack_a);
int		check_sorted(t_stack *stack_a, int size);

// Moves functions

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rotate_a(t_stack **a, int *cost);
void	do_rotate_b(t_stack **b, int *cost);
void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	push_b_below_median(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack_a);
void	rotate(t_stack **stack_a);
void	swap(t_stack **stack_a);

// Linked lists functions

void	index_list(t_stack *stack_a);
void	lst_addback(t_stack **stack_a);
t_stack	*lst_last(t_stack *stack_a);
int		lst_size(t_stack *stack_a);
void	to_int_list(char **array, int position, t_stack *stack_a);

// Positioning functions

int		find_median(int size);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
int		get_lowest_index_position(t_stack **stack);
void	get_position(t_stack **stack_a);
int		get_target(t_stack **a, int b_idx, int target_idx, int target_pos);
void	get_target_position(t_stack **a, t_stack **b);
int		nb_abs(int nb);
void	position_stacks(t_stack **stack_a, t_stack **stack_b);

void	free_stack(t_stack *stack_a);

#endif