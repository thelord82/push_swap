/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:07:10 by malord            #+#    #+#             */
/*   Updated: 2022/09/19 11:08:06 by malord           ###   ########.fr       */
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

#endif