/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:06:42 by malord            #+#    #+#             */
/*   Updated: 2022/09/27 15:13:08 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a)
{
	t_stack	*new_head;
	t_stack	*tmp;
	t_stack	*tmp_2;

	new_head = (*stack_a)->next;
	tmp = *stack_a;
	tmp_2 = (*stack_a)->next->next;
	*stack_a = new_head;
	(*stack_a)->next = tmp;
	(*stack_a)->next->next = tmp_2;
}

void	do_sa(t_stack **stack_a)
{
	swap (stack_a);
	printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
