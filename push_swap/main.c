/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:36:21 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/14 02:20:45 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	else if (!(*argv[1]))
		error_free(NULL, argv, false);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = NULL;
	b = NULL;
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			big_sort(&a, &b);
	}
	if (argc == 2)
		free_matrix(argv + 1);
	free_stack(&a);
}
