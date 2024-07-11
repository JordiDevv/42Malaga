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

static void	get_stack_a(int argc, char *argv[])
{
	t_stack	*node;
	int		i;
	
	i = 1;
	node = ft_new_node(ft_atoi(argv[i]), i);
    while (++i < argc)
		node = ft_next_node(node, ft_new_node(ft_atoi(argv[i]), i));
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		get_stack_a(argc, argv);
	return (0);
}
