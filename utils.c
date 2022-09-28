/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:18 by malord            #+#    #+#             */
/*   Updated: 2022/09/28 09:40:28 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Frees memory of the stack
void	free_stack(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

//Returns the absolute value / distance to zero of a number (-6 is 6)
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

//Finds the median of the linked list
int	find_median(int size)
{
	int	median;

	if (size % 2 == 0)
		median = size / 2;
	else
		median = (size / 2) + 1;
	return (median);
}
