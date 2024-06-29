/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:13 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/17 16:35:03 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrtohex(void *p)
{
	uintptr_t		ptr;
	int				len;

	len = 0;
	ptr = (uintptr_t)p;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex(ptr, 0, 0);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_casthex(unsigned int n, int u)
{
	int	len;

	len = ft_puthex((unsigned long long)n, 0, u);
	if (len == -1)
		return (-1);
	return (len);
}
