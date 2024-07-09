/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:36:21 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/07/09 19:12:15 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void static	get_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	t_stack	*node;
	t_stack	*next_node;
	int		i;
	
	i = 1;
	node = ft_new_node(ft_atoi(argv[i]), i);
    while (i++ < argc - 1)
	{
		next_node = ft_new_node(ft_atoi(argv[i]), i);
		node->next = next_node;
	}
}

int	main(int argc, char *argv[])
{
	get_stack_a(&stack_a, argc, argv);
	return (0);
}
