/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:21:47 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/09 12:58:56 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_stack *node)
{
	node->value = 0;
    node->current_position = 0;
    node->push_price = 0;
    node->index = 0;
    node->above_median = false;
    node->cheapest = false;
    node->target_node = NULL;
    node->next = NULL;
    node->prev = NULL;
}

static long	ft_atol(const char *str)
{
	long    n;
	int		is_neg;
	int		i;

	n = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')

		i++;
	else if (str[i] == '-')
	{
		is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * is_neg);
}

void	stack_init(t_stack **a, char **argv, int flag_2_arg)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_2_arg);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, argv, flag_2_arg);
		if (error_repetition(*a, (int)n))
			error_free(a, argv, flag_2_arg);
		append_node(a, (int)n);
		++i;
	}
}
