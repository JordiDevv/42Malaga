/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:24:19 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/07/18 19:24:19 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    swap(t_stack **node_ref, int ss)
{
    t_stack *node;
    t_stack *aux;
    
    node = *node_ref;
    aux = node->next;
    node->next = aux->next;
    aux->next->prev = node;
    aux->next = node;
    aux->prev = node->prev;
    node->prev->next = aux;
    node->prev = aux;
    if (node->stack == 'a' && ss == 0)
        write(1, "sa\n", 3);
    else if (node->stack == 'b' && ss == 0)
        write(1, "sb\n", 3);
}

void    ss(t_stack **node_ref_a, t_stack **node_ref_b)
{
    t_stack *node;

    node = *node_ref_a;
    swap(&node, 1);
    node = *node_ref_b;
    swap(&node, 1);
    write(1, "ss\n", 3);
}

/*void    refresh_index(t_stack *node, t_stack *aux, char order)
{
    node = aux->next;

    if (order == '-')
        while (node != aux)
        {
            node->index -= 1;
            node = node_a->next;
        }
    else if (order == '+')
        while (node != aux)
        {
            node->index += 1;
            node = node_a->next;
        }
}*/

/*void    push_b(t_stack **node_ref_a, t_stack **node_ref_b)
{
    t_stack *node_a;
    t_stack *node_b;
    t_stack *aux;

    node_a = *node_ref_a;
    node_b = *node_ref_b;
    aux = node_a->next;
    aux->prev = node_a->prev;
    node_a->prev->next = aux;
    node_a->stack = 'b';
    refresh_index(node_a, aux, '-');
    node_a->next = node_b;
    aux = node_b->prev;
    node_b->prev = node_a;
    node_a->prev = aux;
    aux->next = node_a;
    refresh_index(node_b, aux, '+');
    write(1, "pb\n", 3);
}*/

/*void    push_a(t_stack **node_ref_a, t_stack **node_ref_b)
{
    t_stack *node_a;
    t_stack *node_b;
    t_stack *aux;

    node_a = *node_ref_a;
    node_b = *node_ref_b;
    aux = node_b->next;
    aux->prev = node_b->prev;
    node_b->prev->next = aux;
    node_b->stack = 'b';
    refresh_index(node_b, aux, '-');
    node_b->next = node_a;
    aux = node_a->prev;
    node_a->prev = node_b;
    node_b->prev = aux;
    aux->next = node_b;
    refresh_index(node_a, aux, '+');
    write(1, "pa\n", 3);
}*/