/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:13 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/12 18:08:32 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtohex(void *p)
{
	uintptr_t	value;
	const char	*hex_digits;
	static char	buffer[2 + sizeof(uintptr_t) * 2];
	int			i;

	value = (uintptr_t)p;
	i = 1 + sizeof(uintptr_t) * 2;
	hex_digits = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	while (i > 1)
	{
		buffer[i--] = hex_digits[value & 0xf];
		value >>= 4;
	}
	//buffer[2 + sizeof(void *) * 2] = '\0';
	return (buffer);
}
