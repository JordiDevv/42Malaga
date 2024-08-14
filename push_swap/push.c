/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 01:58:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/11 23:25:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if ((*src) == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	set_current_position(*a);
	set_current_position(*b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	set_current_position(*a);
	set_current_position(*b);
	write(1, "pb\n", 3);
}
