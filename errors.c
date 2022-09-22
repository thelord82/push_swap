/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:01 by malord            #+#    #+#             */
/*   Updated: 2022/09/21 19:14:58 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	head = stack_a;
	while (stack_a != NULL)
	{
		tmp = head;
		while (tmp != NULL)
		{
			if (stack_a->nb == tmp->nb && stack_a != tmp)
			{
				write (2, "Error\n", 6);
				exit(0);
			}
			else
				tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

/*void	check_limits(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		if (stack_a->nb < INT_MIN || stack_a->nb > INT_MAX)
		{
			write (2, "Error\n", 6);
			exit(0);
		}
		else
			stack_a = stack_a->next;
	}
}*/

void	check_limits(char **array, int position)
{
	while (array[position])
	{
		if (ft_strlen(array[position]) > 11
			|| (ft_atol(array[position]) < INT_MIN)
			|| (ft_atol(array[position]) > INT_MAX))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			position++;
	}

}

void	check_numbers(char **argv, int index)
{
	int	j;

	while (argv[index])
	{
		j = 0;
		while (argv[index][j])
		{
			if (argv[index][0] == '-' && j == 0)
				j++;
			if (ft_isdigit(argv[index][j]) == 0)
			{
				write (2, "Error\n", 6);
				exit (0);
			}
			else
				j++;
		}
		index++;
	}
}

int	check_sorted(t_stack *stack_a, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (stack_a->nb < stack_a->next->nb)
		{
			stack_a = stack_a->next;
			index++;
			if (index == size - 1)
				exit (0);
		}
		else
			return (0);
	}
	return (0);
}

void	check_split(char **argv, t_stack *stack_a)
{
	stack_a->quoted_args = ft_split(argv[1], ' ');
	check_numbers(stack_a->quoted_args, 0);
	check_limits(stack_a->quoted_args, 0);
	to_int_list(stack_a->quoted_args, 0, stack_a);
	check_doubles(stack_a);
	check_sorted(stack_a, lst_size(stack_a));
}
