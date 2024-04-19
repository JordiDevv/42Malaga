/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/16 18:28:14 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	subs = malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while (i < len)
	{
		subs[start] = s[start];
		i++;
		start++;
	}
	subs[start + len] = '\0';
	return (subs);
}
