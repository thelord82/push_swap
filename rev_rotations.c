/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:11:41 by malord            #+#    #+#             */
/*   Updated: 2022/09/20 15:12:32 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*temp_head;
	t_stack	*new_head;
	int		i;
	int		size;

	i = 1;
	head = *stack_a;
	size = lst_size(head);
	temp_head = lst_last(*stack_a);
	new_head = temp_head;
	temp_head->next = head;
	while (i < size)
	{
		head = head->next;
		temp_head = temp_head->next;
		i++;
	}
	temp_head->next = NULL;
	*stack_a = new_head;
}

void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
}