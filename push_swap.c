/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/20 16:31:49 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addfront(t_stack *stack_a, t_stack *to_add)
{
	t_stack	*new_head;

	new_head = to_add;
	new_head->next = stack_a;
	stack_a = new_head;
}

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

int		find_median(int size)
{
	int	median;

	if (size % 2 == 0)
		median = size / 2;
	else
		median = (size / 2) + 1;
	return (median);
}

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

int	main(int argc, char **argv)
{
	int		position;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*head;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_b = NULL;
	head = stack_a;
	if (!stack_a)
		exit (0);
	position = 1;
	if (argc == 2 && ft_strlen(argv[1]) > 1)
		check_split(argv, stack_a);
	else if (argc > 2)
	{
		check_numbers(argv, 1);
		to_int_list(argv, position, stack_a);
		check_limits(stack_a);
		check_doubles(stack_a);
		check_sorted(stack_a, argc - 1);
	}
	index_list(stack_a);

	// PRINT TESTS 
	while (stack_a != NULL)
	{
		printf("stack_a->nb = %d | stack_a->index = %d\n", stack_a->nb, stack_a->index);
		stack_a = stack_a->next;
	}
	printf("--------\n");
	stack_a = head;
	if (lst_size(stack_a) == 3)
	{
		sort_three(&stack_a);
		while (stack_a != NULL)
		{
			printf("stack_a->nb = %d | stack_a->index = %d\n", stack_a->nb, stack_a->index);
			stack_a = stack_a->next;
		}
	}
	else if (lst_size(stack_a) > 3)
	{
		printf("Plus que 3 connard\n");
		push_b_below_median(&stack_a, &stack_b);
		printf("-----------------\n");
		int i = 0;
		int list_size = lst_size(stack_a) - 3;
		printf("Moves vers stack_b restant pour garder 3 dans stack_a : %d\n", list_size);
		while (i < list_size)
		{
			do_pb(&stack_a, &stack_b);
			i++;
		}
		position_stacks(&stack_a, &stack_b);
		while (stack_b != NULL)
		{
			printf("stack_b->nb = %d | stack_b->index = %d | stack_b->position = %d\n", stack_b->nb, stack_b->index, stack_b->position);
			stack_b = stack_b->next;
		}
		printf("-----------------\n");
		
		while (stack_a != NULL)
		{
			printf("stack_a->nb = %d | stack_a->index = %d | stack_a->position = %d\n", stack_a->nb, stack_a->index, stack_a->position);
			stack_a = stack_a->next;
		}
	}
	return (0);
}
