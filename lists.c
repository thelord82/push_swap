/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:26:31 by malord            #+#    #+#             */
/*   Updated: 2022/09/21 16:13:03 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_int_list(char **array, int position, t_stack *stack_a)
{
	while (array[position])
	{
		stack_a->nb = ft_atol(array[position]);
		if (array[position + 1] != NULL)
			stack_a->next = ft_calloc(sizeof(t_stack), 1);
		else
			stack_a->next = NULL;
		//if (!stack_a->next)
			//exit (0);
		stack_a = stack_a->next;
		position++;
	}
}

int	lst_size(t_stack *stack_a)
{
	t_stack	*list;
	int		size;

	list = stack_a;
	size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void	index_list(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*compared;

	head = stack_a;
	while (head != NULL)
	{
		compared = stack_a;
		while (compared != NULL)
		{
			if (compared->nb <= head->nb)
				head->index++;
			compared = compared->next;
		}
		head = head->next;
	}
}

t_stack	*lst_last(t_stack *stack_a)
{
	t_stack	*head;
	int	i;

	i = 0;
	head = stack_a;
	while (i < lst_size(head) - 1)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (stack_a);
}

void	lst_addback(t_stack **stack_a)
{
	t_stack	*last;

	last = lst_last(*stack_a);
	last->next = *stack_a;
	last->next->next = NULL;
}
