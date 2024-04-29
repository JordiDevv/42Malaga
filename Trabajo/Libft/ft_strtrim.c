/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:36:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/04/29 12:14:14 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strset(char const *s, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)s;
	if (set[j])
	{
		while (str[i] == set[j])
		{
			str[i] = 0;
			i++;
			while (str[i] != set[j] && set[j])
				j++;
		}
	}
	return (str);
}

static char	*ft_strrset(char const *s, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s) - 1;
	j = 0;
	str = (char *)s;
	if (set[j])
	{
		while (str[i] == set[j])
		{
			str[i] = 0;
			i--;
			while (str[i] != set[j] && set[j])
				j++;
		}
	}
		return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str = ft_strset(s1, set);
	str = ft_strrset((char const *)str, set);
	return (str);
}
