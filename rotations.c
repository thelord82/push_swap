/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:09:12 by malord            #+#    #+#             */
/*   Updated: 2022/09/20 15:10:55 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack_a)
{
	t_stack	*new_head;

	new_head = (*stack_a)->next;
	lst_addback(stack_a);
	*stack_a = new_head;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate (stack_a);
	rotate(stack_b);
	printf("rr\n");
}
