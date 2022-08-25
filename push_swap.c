/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/08/25 15:35:42 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_list(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->nb;
	a->nb = b->nb;
	b->nb = tmp;
}

int ascending(int a, int b)
{
	return (a <= b);
}

t_stack *sort_list(t_stack *lst, int (*cmp)(int, int))
{
	t_stack *new;

	new = lst;
	while (lst->next != 0)
	{
		if (((*cmp)(lst->nb, lst->next->nb)) == 0)
		{
			ft_swap_list(lst, lst->next);
			lst = new;
		}
		else
			lst = lst->next;
	}
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*head;
	t_stack	*tmp_node;
	int		i;
	int		tmp;

	i = 1;
	stack_a = ft_calloc(sizeof(t_stack), 1);
	head = stack_a;
	if (argc > 1)
	{
		while (argv[i])
		{
			tmp = ft_atoi(argv[i]);
			stack_a->nb = tmp;
			i++;
			if (argv[i] != NULL)
			{
				tmp_node = ft_calloc(sizeof(t_stack), 1);
				stack_a->next = tmp_node;
				stack_a = stack_a->next;
			}
		}
		stack_a = head;
		stack_a = sort_list(stack_a, ascending);
		i = 0;
		while (stack_a)
		{
			printf("Element %d : %d\n", i, stack_a->nb);
			stack_a = stack_a->next;
			i++;
		}
	}
}

/*int	main(int argc, char **argv)
{
	int	*stack_a;
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack_a = ft_calloc((argc - 1), sizeof(int));
	while (argv[i])
	{
		stack_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	i = 0;
	sort_int_tab(stack_a, (argc - 1));
	while (stack_a[i])
	{
		printf("Element %d : %d\n", i, stack_a[i]);
		i++;
	}
	return (0);
}*/
