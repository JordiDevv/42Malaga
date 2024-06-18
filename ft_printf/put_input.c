/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:12:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/17 16:05:10 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putint(int n)
{
	int	len;

	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	len = 0;
	if (n < 0 && ++len)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putint(n / 10);
		if (len == -1)
			return (-1);
	}
	ft_putchar ('0' + (n % 10));
	return (len + 1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putun(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len = ft_putun(n / 10);
		if (len == -1)
			return (-1);
	}
	ft_putchar ('0' + (n % 10));
	return (len + 1);
}
