/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:58:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/14 02:52:41 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int		        value;
	int				current_position;
	int				push_price;
	int				index;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack  *next;
	struct s_stack	*prev;
}			        t_stack;
char	**ft_split(char *s, char c);
void	stack_init(t_stack **a, char **input, int flag_2_arg);
int		stack_len(t_stack *stack);
int		error_repetition(t_stack *a, int nbr);
int		error_syntax(char *str_nbr);
void    error_free(t_stack **a, char **argv, bool flag_2_arg);
void	free_stack(t_stack **stack);
void    free_matrix(char **argv);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void	init_node(t_stack *node);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_last_node(t_stack *head);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_highest(t_stack *stack);
void	set_current_position(t_stack *stack);
void	set_nodes(t_stack *a, t_stack *b);
void	move_nodes(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	tiny_sort(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);

#endif
