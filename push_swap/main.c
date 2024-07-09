/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:36:21 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/07/09 17:37:15 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void static	get_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	t_stack	tmp;
	int		prueba;
	
	stack_a->next = NULL;
    while (argc > 1)
	{
		stack_a->value = ft_atoi(argv[argc--]);
		prueba = stack_a->value;
		tmp.next = stack_a;
		*stack_a = tmp;
		printf("%d", prueba);
	}
}

int	main(int argc, char *argv[])
{
    static t_stack	stack_a;
	
	get_stack_a(&stack_a, argc, argv);
	return (0);
}