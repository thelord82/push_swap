/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/13 16:45:44 by malord           ###   ########.fr       */
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
		//if (stack_a->next == NULL)
			//return (stack_a);
		stack_a = stack_a->next;
		i++;
	}
	return (stack_a);
}

void	lst_addback(t_stack *stack_a)
{
	t_stack	*last;

	last = lst_last(stack_a);
	last->next = stack_a;
	last->next->next = NULL;
}

void	lst_addfront(t_stack *stack_a, t_stack *to_add)
{
	t_stack	*new_head;

	new_head = to_add;
	new_head->next = stack_a;
	stack_a = new_head;
}

t_stack	*do_sa(t_stack *stack_a)
{
	int	tmp;
	int	tmp_index;

	tmp = stack_a->nb;
	tmp_index = stack_a->index;
	stack_a->nb = stack_a->next->nb;
	stack_a->index = stack_a->next->index;
	stack_a->next->nb = tmp;
	stack_a->next->index = tmp_index;
	printf("sa\n");
	return (stack_a);
}

t_stack	*do_ra(t_stack *stack_a)
{
	t_stack	*new_head;

	new_head = stack_a->next;
	lst_addback(stack_a);
	stack_a = new_head;
	printf("ra\n");
	return (stack_a);
}

t_stack *do_rra(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*temp_head;
	t_stack	*new_head;
	int		i;
	int		size;

	i = 1;
	head = stack_a;
	size = lst_size(head);
	temp_head = lst_last(stack_a);
	new_head = temp_head;
	temp_head->next = head;
	while (i < size)
	{
		head = head->next;
		temp_head = temp_head->next;
		i++;
	}
	temp_head->next = NULL;
	printf("rra\n");
	return (new_head);
}

t_stack	*sort_three(t_stack *stack_a) // Verifier le print si au bon endroit ? Correct d'appeler les fonctions de moves entre eux? Ce sont des moves ou non? 
{
	t_stack *head;

	head = stack_a;
	while (check_sorted(head, lst_size(head)) != 1)
	{
		if (head->index > head->next->index && head->index > head->next->next->index)
			head = do_ra(head);
		else if (head->next->index > head->index && head->next->index > head->next->next->index)
			head = do_rra(head);
		else if (head->index > head->next->index)
			head = do_sa(head);
	}
	return (head);
}

int	main(int argc, char **argv)
{
	int		position;
	t_stack	*stack_a;
	t_stack	*head;
	t_stack	*result;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	head = stack_a;
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
	while (stack_a != NULL)
	{
		printf("stack_a->nb = %d | stack_a->index = %d\n", stack_a->nb, stack_a->index);
		stack_a = stack_a->next;
	}
	printf("--------\n");
	stack_a = head;
	result = sort_three(stack_a);
	while (result != NULL)
	{
		printf("stack_a->nb = %d | stack_a->index = %d\n", result->nb, result->index);
		result = result->next;
	}
	return (0);
}
