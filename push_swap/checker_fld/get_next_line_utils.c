/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:39:24 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/22 11:39:24 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		cat;
	int		i;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	cat = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++cat])
		str[i + cat] = s2[cat];
	str[i + cat] = 0;
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == 0)
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
