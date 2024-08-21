/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:16:36 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/13 17:23:48 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_push_filter(t_stack **a, t_stack **b, int len_a, int i)
{
	t_stack	**middle_checker;

	while (i > 3)
	{
		middle_checker = a;
		if (middle_checker && *middle_checker)
		{
			while (*middle_checker && !((*middle_checker)->index <= len_a / 2))
				middle_checker = &(*middle_checker)->next;
		}
		if (!(*middle_checker))
			break ;
		while (*a != *middle_checker)
		{
			if (!(*middle_checker))
				break ;
			if ((*middle_checker)->above_median)
				ra(a);
			else
				rra(a);
		}
		pb(b, a);
		i--;
	}
	return (i);
}

static void	set_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*aux;
	int		len_a;
	int		i;

	len_a = stack_len(a);
	tmp = a;
	while (tmp)
	{
		aux = a;
		i = 0;
		while (aux)
		{
			if (tmp->value < aux->value)
				i++;
			aux = aux->next;
		}
		tmp->index = len_a - i;
		tmp = tmp->next;
	}
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;
	int		i;

	len_a = stack_len(*a);
	i = len_a;
	set_index(*a);
	if (len_a > 100)
		i = init_push_filter(a, b, len_a, i);
	while (i-- > 3)
		pb(b, a);
	tiny_sort(a);
	while (*b)
	{
		set_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
