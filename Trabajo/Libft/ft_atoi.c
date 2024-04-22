/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:19:20 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/23 00:22:09 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	sign;
	int	r;

	sign = 0;
	r = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
		sign = *str;
	while (*str == 43 || *str == 45)
		str++;
	while (*str > 47 && *str < 58)
	{
		r *= 10;
		r += *(int)str;
		str++;
	}
	if (sign == '-')
		return (r * -1);
	return (r);
}
