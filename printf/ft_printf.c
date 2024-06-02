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

static void	ft_get_input(int t_return, char *str, va_list args)
{
	str++;
	if (*str == c)
	{
		if (t_return == 1)
			return (1);
		return (*str);
	}
}
	
static int	ft_get_size(char *str_cpy, va_list args_s)
{
	str_cpy++;
	if (*str_cpy == c)
	{
		va_arg(args_s, int);
		r = 1;
	}
	else if (*str_cpy == s)
		r = ft_strlen(va_arg(args_s, char *));
	else if (*str_cpy == p)
	{
		va_arg(args_s, void *);
		r = += 2 + sizeof(void *) * 2;
	}
	else if (*str_cpy == d)
		r = ft_numlen(va_arg(args_s, int));
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
			size += ft_get_size(str_cpy, args_s);
		else
			size++;
		str_cpy++;
	}
	return (size);
}

int	ft_printf(char const *str, ...)
{
	if (!str)
		return (NULL);
	char	*p;
	char	*print;
	va_list	args;
	va_list	args_s;

	p = str;
	va_start(args, p);
	va_copy(args_s, args);
	print = malloc(ft_size_of_print(str, args_s));
	if (!print)
		return (NULL);
	while (*p)
	{
		if(*p == '%')
			*p = ft_get_input(0, p, args);
		p++;
	}
}
	
