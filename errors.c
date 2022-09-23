/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:18:01 by malord            #+#    #+#             */
/*   Updated: 2022/09/23 10:19:59 by malord           ###   ########.fr       */
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
				free_stack(head);
				exit(0);
			}
			else
				tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	check_limits(char **array, int position, int calloc_flag)
{
	while (array[position])
	{
		if (ft_strlen(array[position]) > 11
			|| (ft_atol(array[position]) < INT_MIN)
			|| (ft_atol(array[position]) > INT_MAX))
		{
			write(2, "Error\n", 6);
			if (calloc_flag == 1)
				free_array(array);
			exit(0);
		}
		else
			position++;
	}
}

void	check_numbers(char **argv, int index, int calloc_flag)
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
				if (calloc_flag == 1)
					free_array(argv);
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
	int		index;
	t_stack	*head;

	index = 0;
	head = stack_a;
	if (size <= 1)
	{
		free(stack_a);
		exit (0);
	}
	while (index++ < size)
	{
		if (stack_a->next != NULL && stack_a->nb < stack_a->next->nb)
		{
			stack_a = stack_a->next;
			if (index == size - 1)
			{
				free_stack(head);
				exit (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

void	check_split(char **argv, t_stack **stack_a)
{
	char	**quoted_args;
	int		i;

	i = 0;
	quoted_args = ft_split(argv[1], ' ');
	if (quoted_args[0] == NULL)
	{
		free(quoted_args);
		exit(0);
	}
	check_numbers(quoted_args, 0, 1);
	check_limits(quoted_args, 0, 1);
	*stack_a = ft_calloc(sizeof(t_stack), 1);
	to_int_list(quoted_args, 0, *stack_a);
	while (quoted_args[i])
	{
		free(quoted_args[i]);
		i++;
	}
	free (quoted_args);
	check_doubles(*stack_a);
	check_sorted(*stack_a, lst_size(*stack_a));
}
