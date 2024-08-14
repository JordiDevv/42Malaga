/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:16:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/11 01:27:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
        && !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(a, b);
}
