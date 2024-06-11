/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/11 19:08:19 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_ulen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (!n)
		str[0] = '0';
	str[len] = '\0';
	while (--len >= 0 && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
