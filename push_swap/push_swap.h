/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:58:22 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/07/09 18:45:53 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		        value;
	int				index;
	struct s_stack  *next;
	struct s_stack	*prev;
}			        t_stack;
t_stack	*ft_new_node(int value, int index);
t_stack	*ft_next_node(t_stack *node, t_stack *next_node);
t_stack	*ft_last_node(t_stack *node);

#endif
