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

void static	get_stack_a(int argc, char *argv[])
{
	t_stack	*node;
	t_stack	*next_node;
	int		i;
	
	i = 0;
    while (++i < argc)
	{
		node = ft_new_node(ft_atoi(argv[i]), i);
		if (++i < argc)
		{
			next_node = ft_new_node(ft_atoi(argv[i]), i);
			node->next = next_node;
		}
	}
}

int	main(int argc, char *argv[])
{
	get_stack_a(argc, argv);
	return (0);
}
