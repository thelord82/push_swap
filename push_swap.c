/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/21 20:03:17 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->index > (*stack_a)->next->next->index)
			do_ra(stack_a);
		else if ((*stack_a)->next->index > (*stack_a)->index
			&& (*stack_a)->next->index > (*stack_a)->next->next->index)
			do_rra(stack_a);
		else if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a);
		i++;
	}
}

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = lst_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b_below_median(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!check_sorted((*stack_a), lst_size(*stack_a)))
		shift_stack(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	list_size;

	i = 0;
	if (lst_size(*stack_a) == 2)
		do_sa(stack_a);
	else if (lst_size(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		push_b_below_median(stack_a, stack_b);
		list_size = lst_size(*stack_a) - 3;
		while (i < list_size)
		{
			do_pb(stack_a, stack_b);
			i++;
		}
		position_stacks(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_b = NULL;
	if (!stack_a)
		exit (0);
	if (argc < 2)
		return (0);
	if (argc == 2)
		check_split(argv, stack_a);
	else if (argc > 2)
	{
		check_numbers(argv, 1);
		check_limits(argv, 1);
		to_int_list(argv, 1, stack_a);
		check_doubles(stack_a);
		check_sorted(stack_a, argc - 1);
	}
	index_list(stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
