/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:07:10 by malord            #+#    #+#             */
/*   Updated: 2022/09/20 16:33:08 by malord           ###   ########.fr       */
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
	char				**quoted_args;
	struct s_stacklist	*next;
}		t_stack;

void	check_split(char **argv, t_stack *stack_a);
void	to_int_list(char **array, int position, t_stack *stack_a);
int		check_sorted(t_stack *stack_a, int size);
void	check_errors(char **argv, int index);
void	check_numbers(char **argv, int index);
void	check_doubles(t_stack *stack_a);
void	check_limits(t_stack *stack_a);
int		lst_size(t_stack *stack_a);
void	swap(t_stack **stack_a);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack_a);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack_a);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	lst_addback(t_stack **stack_a);
t_stack	*lst_last(t_stack *stack_a);
void	index_list(t_stack *stack_a);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	push_b_below_median(t_stack **stack_a, t_stack **stack_b);
int		find_median(int size);

#endif