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
	

static int	ft_size_of_print(char *str, va_list args_s)
{
	char 	*start_lo;
	int	size;

	str_lo = str;
	size = 0;
	while (*str_lo)
	{
		if (*str_lo == '%')
			size += ft_get_input(1, str_lo, args_s);
		size++;
		str_lo++;
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
	
