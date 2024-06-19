/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:06 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/17 16:04:24 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_input(char c, va_list args/*, char *i*/)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_ptrtohex(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putun(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_casthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_casthex(va_arg(args, unsigned int), 1));
	else
	{
		ft_putchar('%');
		return (ft_putchar(c) + 1);
	}
	return (0);
}

static int	ft_iterate(const char *str, va_list args, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '%')
				len += ft_putchar('%');
			else
				len += ft_get_input(str[i], args/*, &i*/);
			/*if (len == -1)
				return (-1);*/
		}
		else
		{
			ft_putchar(str[i]);
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
	len = ft_iterate(str, args, len);
	va_end(args);
	return (len);
}
