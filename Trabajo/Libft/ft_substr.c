/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:27:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/26 19:31:09 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;

	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	subs = malloc(len + 1);
	if (!subs)
		return (0);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

/*int main()
{
	char *subs = ft_substr("Ola k ase", 4, 200);
	printf("%s\n", subs);
	return (0);
}*/
