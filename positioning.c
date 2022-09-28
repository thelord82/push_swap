/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:58:34 by malord            #+#    #+#             */
/*   Updated: 2022/09/28 09:15:13 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		position;

	head_a = *stack_a;
	head_b = *stack_b;
	position = 0;
	while (head_a != NULL)
	{
		position++;
		head_a->position = position;
		head_a = head_a->next;
	}
	position = 0;
	while (head_b != NULL)
	{
		position++;
		head_b->position = position;
		head_b = head_b->next;
	}
}

void	get_position(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_cost:
Calculates the cost of moving each element of stack B into the correct
position in stack A.
Two costs are calculated:
	cost_b represents the cost of getting the element to the top of the B stack
	cost_a represents the cost of getting to the right position in stack A.
If the element is in the bottom half of the stack, the cost will be negative,
if it is in the top half, the cost is positive. 
*/

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = lst_size(tmp_a);
	size_b = lst_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > find_median(size_b))
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > find_median(size_a))
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
