/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:36:21 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/05 20:50:55 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static t_stack  *init_stack_b(t_stack *node, t_stack *node2, t_stack *node3)
{
    node->next = node2;
    node2->next = node;
    node->prev->next = node3;
    node3->prev = node->prev;
    node->prev = node2;
    node->stack = 'b';
    node2->stack = 'b';
    return (node2);
}

static void sort(t_stack *node_a)
{
    t_stack *node_b;

    node_b = init_stack_b(node_a, node_a->next, node_a->next->next);
    if (node_b)
        printf (":)");
    else
        printf (":(");
    //push(node_a, node_b);
    //if (node->value > node->next->value)
        //swap(&node_a, 0);
}

static void sort_index(t_stack *node, int max_in)
{
    t_stack *aux;
    int     i;
    int     j;

    i = 1;
    while (i != max_in)
    {
        j = 1;
        aux = node;
        while (j != max_in - 1)
        {
            aux = aux->next;
            if (node->value > aux->value)
                node->index++;
            j++;
        }
        i++;
        node = node->next;
    }
}

static void get_stack_a(int argc, char *argv[])
{
    t_stack *node;
    t_stack *head_a;
    int i;
    
    i = 1;
    node = ft_new_node(ft_atoi(argv[i]), 'a');
    head_a = node;
    while (++i < argc)
	{
        node = ft_next_node(node, ft_new_node(ft_atoi(argv[i]), 'a'));
	}
    sort_index(head_a, argc);
    if (argc == 3)
    {
        if (node->value < node->next->value)
            swap(&node, 0);
    }
    else
        sort(node->next);
}

int main(int argc, char *argv[])
{
    if (argc > 2)
        get_stack_a(argc, argv);
    return (0);
}
