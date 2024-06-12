/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:12:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/12 19:29:17 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

static int	int_min(int n)
{
	(void)n;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putint(int n)
{
	int	let;

	let = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++let)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		let += ft_putnbr(n / 10);
		if (let == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		let++;
	}
	return (let);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (write(1, &s[i], 1) != 1)
			return (-1);
		i++;
	}
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
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		len++;
	}
	return (len);
}