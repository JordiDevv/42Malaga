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

void	ft_get_input_root(char **str, char **print, va_list args)
{
	while (**str)
	{
		if (**str == '%')
		{
			*str++;
			ft_get_input(str, print, args);
		}
		else
			*(*print)++ = *(*str)++;
	}
}

int	ft_printf(char const *str, ...)
{
	if (!str)
		return (-1);
	char	*print;
	char	*print_origin;
	va_list	args;
	va_list	args_s;
	int	size;

	va_start(args, p);
	va_copy(args_s, args);
	size = ft_size_of_print(str, args_s);
	print = malloc(size + 1);
	va_end(args_s);
	print_origin = print;
	if (!print)
	{
		va_end(args);
		return (-1);
	}
	ft_get_input_root(&str, &print, args);
	write(1, print_origin, size);
	free(print_origin);
	va_end(args);
	return (size);
}	
