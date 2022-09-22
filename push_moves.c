/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:31:04 by malord            #+#    #+#             */
/*   Updated: 2022/09/22 14:48:55 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	printf("pb\n");
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	printf("pa\n");
}

void	push_b_below_median(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		median;
	int		i;

	size = lst_size(*stack_a);
	i = 0;
	median = find_median(size);
	while (i < size && lst_size(*stack_a) > 3)
	{
		if (lst_size(*stack_b) == 0
			&& check_sorted(*stack_a, lst_size(*stack_a)) == 1)
			break ;
		if ((*stack_a)->index <= median)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		i++;
	}
}
