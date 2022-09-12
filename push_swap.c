/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/12 16:51:15 by malord           ###   ########.fr       */
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

int		check_sorted(t_stack *stack_a, int size)
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
				return (1);
				//exit (0);
			}
		}
		else
		{
			printf("This is not sorted you fuck\n");
			return (0);
		}
	}
	return (0);
}

void	to_int_list(char **array, int position, t_stack *stack_a)
{
	while (array[position])
	{
		stack_a->nb = ft_atoi(array[position]);
		stack_a->next = ft_calloc(sizeof(t_stack), 1);
		//if (!stack_a->next)
			//exit (0);
		stack_a = stack_a->next;
		position++;
	}
	free(stack_a);
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

void	do_sa(t_stack *stack_a)
{
	int	tmp;
	int	tmp_index;

	tmp = stack_a->nb;
	tmp_index = stack_a->index;
	stack_a->nb = stack_a->next->nb;
	stack_a->index = stack_a->next->index;
	stack_a->next->nb = tmp;
	stack_a->next->index = tmp_index;
}

void	do_ra(t_stack *stack_a)
{
	t_stack	*head;
	int		i = 0;

	head = stack_a;
	while (head->next != NULL && i < lst_size(stack_a) - 1)
	{
		do_sa(head);
		head = head->next;
		i++;
	}
}

void	do_rra(t_stack *stack_a)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (i < lst_size(head) - 1)
	{
		do_ra(head);
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_three(t_stack *stack_a)
{
	t_stack *head;

	head = stack_a;
	while (check_sorted(stack_a, lst_size(stack_a)) != 1)
	{
		if (head->index > head->next->index && head->index > head->next->next->index)
		{
			do_ra(stack_a);
			printf("ra\n");
		}
		else if (head->next->index > head->index && head->next->index > head->next->next->index)
		{
			do_rra(stack_a);
			printf("rra\n");
		}
		else if (head->index > head->next->index)
		{
			do_sa(stack_a);
			printf("sa\n");
		}
	}
}

int	main(int argc, char **argv)
{
	int		position;
	t_stack	*stack_a;
	t_stack	*head;
	//t_stack	*stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	head = stack_a;
	//stack_b = ft_calloc(sizeof(t_stack), 1);
	if (!stack_a)
		exit (0);
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
	printf("--------\n");
	stack_a = head;
	sort_three(stack_a);
	while (stack_a->next != NULL)
	{
		printf("stack_a->nb = %d | stack_a->index = %d\n", stack_a->nb, stack_a->index);
		stack_a = stack_a->next;
	}
	/*while (stack_b->next != NULL)
	{
		printf("stack_b->nb = %d | stack_b->index = %d\n", stack_b->nb, stack_b->index);
		stack_b = stack_b->next;
	}*/
	return (0);
}
