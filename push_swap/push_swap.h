/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:58:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/04 12:58:30 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		        value;
	int				index;
	struct s_stack  *next;
	struct s_stack	*prev;
	char			stack;
}			        t_stack;
t_stack	*ft_new_node(int value, char stack);
t_stack	*ft_next_node(t_stack *node, t_stack *next_node);
t_stack	*ft_last_node(t_stack *node);
t_stack	*ft_seek_node(t_stack *node, int index);
void    swap(t_stack **node_ref, int ss);
void	ss(t_stack **node_ref_a, t_stack **node_ref_b);
void	refresh_index(t_stack *node, t_stack *aux, char order);
void	push_b(t_stack **node_ref_a, t_stack **node_ref_b);
void	push_a(t_stack **node_ref_a, t_stack **node_ref_b);

#endif
