/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:06:30 by malord            #+#    #+#             */
/*   Updated: 2022/08/24 14:20:06 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
}
