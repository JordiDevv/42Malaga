/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:41:07 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/11 01:41:07 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i++ <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}

static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	if (!a || !b)
		return ;
	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

static void	set_cheapest(t_stack *b)
{
	long	cheapest;
	t_stack	*match_node;

	if (!b)
		return ;
	cheapest = LONG_MAX;
	while (b)
	{
		if (b->push_price < cheapest)
		{
			cheapest = b->push_price;
			match_node = b;
		}
		b = b->next;
	}
	match_node->cheapest = true;
}

void	set_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
