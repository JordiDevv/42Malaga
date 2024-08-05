/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:40:15 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/03 15:40:56 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_new_node(int value, char stack)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = 1;
    new_node->next = new_node;
    new_node->prev = new_node;
    new_node->stack = stack;
    return (new_node);
}

t_stack *ft_next_node(t_stack *node, t_stack *next_node)
{
    t_stack *last;

    if (!node)
        return (next_node);
    node = ft_seek_node(node, 1);
    last = ft_last_node(node);
    last->next = next_node;
    next_node->prev = last;
    next_node->next = node;
    node->prev = next_node;
    
    return (next_node);
}

t_stack *ft_last_node(t_stack *node)
{
    t_stack *start = node;

    if (node)
    {
        while (node->next != start)
            node = node->next;
    }
    return (node);
}

t_stack *ft_seek_node(t_stack *node, int index)
{
    t_stack *start = node;

    while (node->index != index)
    {
        node = node->next;
        if (node == start)
            break;
    }
    return (node);
}
