/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:31:04 by malord            #+#    #+#             */
/*   Updated: 2022/09/20 16:32:19 by malord           ###   ########.fr       */
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
	t_stack	*head;
	int		size;
	int		median;
	int		i;

	head = NULL;
	size = lst_size(*stack_a);
	i = 0;
	median = find_median(size);
	while (i < size)
	{
		if ((*stack_a)->index < median)
			do_pb(stack_a, stack_b);
		else
		{
			if (head == NULL)
				head = *stack_a;
			do_ra(stack_a);
		}
		i++;
	}
	if ((*stack_a) == NULL)
		*stack_a = head;
}
