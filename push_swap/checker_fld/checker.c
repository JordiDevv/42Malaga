/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:19:38 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/15 19:06:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;

	if (argc == 1)
		return (1);
	else if (!(*argv[1]))
		error(NULL, NULL);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = NULL;
	b = NULL;
	stack_init(&a, argv + 1, argc == 2);
	len = stack_len(a);
	next_line = get_next_line(0);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(0);
	}
	write_res(a);
	free(a);
}
