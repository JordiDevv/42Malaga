/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:56:58 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/21 17:00:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	write_res(t_stack *a)
{
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
