/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:06 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/12 19:29:03 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_input(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_ptrtohex(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(args, int)));
	if (c == 'u')
		return (ft_putun(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_casthex(va_arg(args, int), 0));
	if (c == 'X')
		return (ft_casthex(va_arg(args, int), 1));
	return (0);
}

static int	get_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c != '%')
	{
		len = get_input(c, args);
		if (len == -1)
			return (-1);
		return (len);
	}
	else
	{
		if (write (1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

static int	w_print(const char *str, va_list args, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += get_format(str[i + 1], args);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &str[i], 1) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	len = w_print(str, args, len);
	va_end(args);
	return (len);
}