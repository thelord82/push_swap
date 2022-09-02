/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/09/02 17:36:00 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*head;
	t_stack	*tmp_node;
	int		i;
	int		tmp;

	i = 1;
	stack_a = ft_calloc(sizeof(t_list), 1);
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
				tmp_node = ft_calloc(sizeof(t_list), 1);
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
}*/
void	check_limits(char **argv, int index)
{
	while (argv[index])
	{
		if (ft_atol(argv[index]) > INT_MAX || ft_atol(argv[index]) < INT_MIN)
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

void	check_sorted(int	*numarray, int size)
{
	int	index;

	index = 1;
	int i = 0;
	while (i < size)
	{
		printf("Valeur de numarray[%d] = : %d\n", i, numarray[i]);
		i++;
	}
	while (index < size && numarray[index + 1] != 0)
	{
		if ((numarray[index] > numarray[index - 1])
			&& (numarray[index] < numarray[index + 1]))
		{
			index++;
			if (numarray[index + 1] == 0)
				printf("This is already sorted cockhead!\n");
		}
		else
		{
			printf("This is not sorted you fuck\n");
			break ;
		}
	}
}

int	*convert_to_int(char **array, int index)
{
	int	*converted;
	int	i;

	i = 0;
	converted = ft_calloc(index, sizeof(int));
	index = 0;
	if (ft_isint(ft_atoi(array[0])) == 0)
	{
		printf("Chu rentrer\n");
		i = 1;
	}
	printf("Valeur i : %d\n", i);
	printf("contenu de l'array : %s\n", array[i]);
	while (array[i])
	{
		converted[index] = ft_atoi(array[i]);
		index++;
		i++;
	}
	return (converted);
}

void	check_split(char **argv)
{
	char	**quoted_args;
	int		i;
	int		*converted;

	i = 0;
	quoted_args = ft_split(argv[1], ' ');
	while (quoted_args[i])
	{
		printf("Valeur de quoted_args[%d] = %s\n", i, quoted_args[i]);
		i++;
	}
	if (i >= 1)
	{
		check_errors(quoted_args, 0);
		converted = convert_to_int(quoted_args, i);
		printf("valeur de converted[0] = %d\n", converted[0]);
		printf("valeur de converted[1] = %d\n", converted[1]);
		printf("valeur de converted[2] = %d\n", converted[2]);
		check_sorted(converted, i);
	}
}

int	main(int argc, char **argv)
{
	int	*converted;

	if (argc == 2)
		check_split(argv);
	else if (argc > 2)
	{
		converted = convert_to_int(argv, argc - 1);
		printf("valeur de converted[0] = %d\n", converted[0]);
		printf("valeur de converted[1] = %d\n", converted[1]);
		printf("valeur de converted[2] = %d\n", converted[2]);
		check_sorted(converted, argc - 1);
		check_errors(argv, 1);
	}
	exit (0);
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
