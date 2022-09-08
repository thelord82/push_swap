/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/08 15:49:24 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(char **argv, int index)
{
	while (argv[index])
	{
		if (((int)ft_strlen(argv[index]) > 11)
			|| (ft_atol(argv[index]) < INT_MIN
				|| ft_atol(argv[index]) > INT_MAX))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			index++;
	}
}

void	check_doubles(char **argv, int index)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		index = 0;
		while (argv[index])
		{
			if (ft_strcmp(argv[index], argv[j]) == 0 && index != j)
			{
				write (2, "Error\n", 6);
				exit (0);
			}
			else
				index++;
		}
		j++;
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

void	check_errors(char **argv, int index)
{
	check_limits(argv, index);
	check_doubles(argv, index);
	check_numbers(argv, index);
}

void	check_sorted(t_stack *stack_a, int size)
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
			{
				printf("This is already sorted cockhead!\n");
				exit (0);
			}
		}
		else
		{
			printf("This is not sorted you fuck\n");
			break ;
		}
	}
}

void	to_int_list(char **array, int position, t_stack *stack_a)
{
	while (array[position])
	{
		stack_a->nb = ft_atoi(array[position]);
		stack_a->next = ft_calloc(sizeof(t_stack), 1);
		if (!stack_a->next)
			exit (0);
		stack_a = stack_a->next;
		position++;
	}
}

void	check_split(char **argv, t_stack *stack_a)
{
	stack_a->quoted_args = ft_split(argv[1], ' ');
	check_errors(stack_a->quoted_args, 0);
	to_int_list(stack_a->quoted_args, 0, stack_a);
	check_sorted(stack_a, lst_size(stack_a));
}

int	lst_size(t_stack *stack_a)
{
	t_stack	*list;
	int		size;

	list = stack_a;
	size = 0;
	while (list->next != NULL)
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
	while (head->next != NULL)
	{
		compared = stack_a;
		while (compared->next != NULL)
		{
			if (compared->nb <= head->nb)
				head->index++;;
			compared = compared->next;
		}
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	int		position;
	t_stack	*stack_a;
	t_stack	*head;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	if (!stack_a)
		exit (0);
	head = stack_a;
	position = 1;
	if (argc == 2)
		check_split(argv, stack_a);
	else if (argc > 2)
	{
		check_errors(argv, 1);
		to_int_list(argv, position, stack_a);
		check_sorted(stack_a, argc - 1);
	}
	index_list(stack_a);
	while (stack_a->next != NULL)
	{
		printf("stack_a->nb = %d | stack_a->index = %d\n", stack_a->nb, stack_a->index);
		stack_a = stack_a->next;
	}
	return (0);
}
