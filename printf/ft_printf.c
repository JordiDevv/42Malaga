/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:06 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/11 19:07:48 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_input_root(char **str, char **print, va_list args)
{
	char	*print_origin;

	print_origin = *print;
	while (**str)
	{
		if (**str == '%')
		{
			(*str)++;
			ft_get_input(str, print, args);
		}
		else
			*(*print)++ = *(*str)++;
	}
	*(*print) = '\0';
	write(1, print_origin, *print - print_origin);
	free(print_origin);
}

int	ft_printf(char const *str, ...)
{
	char	*print;
	char	*p;
	va_list	args;
	va_list	args_s;
	int		size;

	if (!str)
		return (-1);
	p = (char *)str;
	va_start(args, str);
	va_copy(args_s, args);
	size = ft_size_of_print(p, args_s);
	print = malloc(size + 1);
	va_end(args_s);
	if (!print)
	{
		va_end(args);
		return (-1);
	}
	ft_get_input_root(&p, &print, args);
	va_end(args);
	return (size);
}
