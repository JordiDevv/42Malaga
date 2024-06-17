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
	int	let;

	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	let = 0;
	if (n < 0 && ++let)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		let += ft_putint(n / 10);
		if (let == -1)
			return (-1);
	}
	if (ft_putchar ('0' + (n % 10)) == -1)
		return (-1);
	return (let + 1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	i = 0;
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
	}
	if (ft_putchar ('0' + (n % 10)) == -1)
		return (-1);
	return (len + 1);
}
