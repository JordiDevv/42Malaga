/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:06 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/05/31 18:43:16 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "jslib.h"

static void	ft_get_input(char *str, char *print, va_list args)
{
	char	*s;

	str++;
	if (*str == 'c')
		*print++ = va_arg(args, int);
	else if (*str == 's')
	{
		s = va_arg(args, char *);
		print += ft_strlcpy(print, s, ft_strlen(s));
	}
}
	
static int	ft_get_size(va_list args_s)
{
	if (*str_cpy == 'c')
	{
		va_arg(args_s, int);
		return (1);
	}
	else if (*str_cpy == 's')
		return (ft_strlen(va_arg(args_s, char *)));
	else if (*str_cpy == 'p')
	{
		va_arg(args_s, void *);
		return (2 + sizeof(void *) * 2);
	}
	else if (*str_cpy == 'd' || *str_cpy == 'i')
		return (ft_numlen(va_arg(args_s, int)));
	else if (*str_cpy == 'u')
		return (ft_numlen(va_arg(args_s, unsigned int)));
	else if (*str_cpy == '%')
		return (1);
	else if (*str_cpy == 'X' || *str_cpy == 'x')
		return (ft_hexlen(va_arg(args_s, unsigned int)));
	return (0);
}

static int	ft_size_of_print(char *str, va_list args_s)
{
	char 	*str_cpy;
	int	size;

	str_cpy = str;
	size = 0;
	while (*str_cpy)
	{
		if (*str_cpy == '%')
		{
			str_cpy++;
			size += ft_get_size(args_s);
		}
		else
			size++;
		str_cpy++;
	}
	return (size);
}

int	ft_printf(char const *str, ...)
{
	if (!str)
		return (-1);
	char	*print;
	va_list	args;
	va_list	args_s;
	int	size;

	va_start(args, p);
	va_copy(args_s, args);
	size = ft_size_of_print(str, args_s);
	print = malloc(size + 1);
	va_end(args_s);
	if (!print)
	{
		va_end(args);
		return (-1);
	}
	while (*str)
	{
		if(*str == '%')
			ft_get_input(str, print, args);
		*print++ = *str++;
	}
	return (size);
}
	
