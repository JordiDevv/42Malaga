/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:40:15 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/07/09 18:45:13 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_next_node(t_stack *node, t_stack *next_node)
{
	t_stack	*last;

	if (!node)
		node = next_node;
	else
	{
		last = ft_last_node(node);
		last->next = next_node;
		next_node->prev = last;
	}
	return(next_node);
}

t_stack	*ft_last_node(t_stack *node)
{
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	return (node);
}
