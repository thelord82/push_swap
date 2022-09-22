/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:06:42 by malord            #+#    #+#             */
/*   Updated: 2022/09/22 09:38:24 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->nb;
	(*stack_a)->nb = (*stack_a)->next->nb;
	(*stack_a)->next->nb = tmp;
	tmp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = tmp;
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
