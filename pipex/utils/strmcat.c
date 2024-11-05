/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:15:23 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/29 18:16:55 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*strmcat(int n, ...)
{
	va_list	args;
	int		len;
	int		i;
	char	*str;
	char	*str_aux;

	va_start(args, n);
	len = 0;
	i = 0;
	while (i++ < n)
	{
		str_aux = va_arg(args, char *);
		len += ft_strlen(str_aux);
	}
	va_start(args, n);
	i = 0;
	str = malloc(len + 1);
	str[0] = 0;
	while (i++ < n)
	{
		str_aux = va_arg(args, char *);
		ft_strcat(str, str_aux);
	}
	va_end(args);
	return (str);
}
