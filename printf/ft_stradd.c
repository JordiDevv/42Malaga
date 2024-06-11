/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:21 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/11 19:05:23 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_stradd(char *dst, char *src, int len)
{
	if (!src && !dst)
		return ;
	while (len)
	{
		*dst++ = *src++;
		len--;
	}
}
