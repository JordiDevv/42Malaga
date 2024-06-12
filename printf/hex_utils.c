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

static char	hex_low[] = "0123456789abcdef";
static char	hex_up[] = "0123456789ABCDEF";

int	ft_puthex(unsigned long long n, int a, int u)
{
	char	bstr[17];

	if (u)
		ft_strlcpy(bstr, hex_low, 17);
	else
		ft_strlcpy(bstr, hex_up, 17);
	if (n >= 16)
	{
		a = ft_puthex(n / 16, a, u);
		if (a == -1)
			return (-1);
		if (write (1, &bstr[n & 0xf], 1) == -1)
			return (-1);
		a++;
	}
	else if (n < 16)
	{
		if (write (1, &bstr[n], 1) == -1)
			return (-1);
		a++;
	}
	return (a);
}

int	ft_ptrtohex(void *p)
{
	unsigned long long	ptr;
	int					len;

	len = 0;
	ptr = (unsigned long long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	len = ft_puthex(ptr, len, 1);
	if (len == -1)
		return (-1);
	len += 2;
	return (len);
}

int	ft_casthex(int n, int u)
{
	unsigned long long	c_n;
	int					len;

	len = 0;
	c_n = (unsigned long long)n;
	len = ft_puthex(c_n, len, u);
	if (len == -1)
		return (-1);
	return (len);
}