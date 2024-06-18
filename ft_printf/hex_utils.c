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

int	ft_puthex(unsigned long long n, int a, int u)
{
	char	bstr[17];

	if (u)
		ft_strlcpy(bstr, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(bstr, "0123456789abcdef", 17);
	if (n >= 16)
	{
		a = ft_puthex(n / 16, a, u);
		if (a == -1)
			return (-1);
	}
	ft_putchar(bstr[n & 0xf]);
	return (a + 1);
}

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
