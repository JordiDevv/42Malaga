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

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

    if (!s)
        return (0);
	i = 0;
	while (s[i++]);
	return (i - 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

    if (!dst || !src)
        return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
    int     cat;
    int     i;

    i = 0;
    if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	cat = ft_strlcpy(str, s1, ft_strlen(s1) + 1);
    free(s1);
	while (s2[i])
        str[cat++] = s2[i++];
    str[cat] = 0;
	return (str);
}

char	*ft_strchr(char *s, int c)
{
    int i;

    i = 0;
	while (s[i])
    {
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
    if (c == 0)
        return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

    if (!s)
        return (0);
	if (ft_strlen(s) <= start)
    {
        sub = malloc(1);
        if (!sub)
            return (NULL);
        sub[0] = 0;
        return (sub);
    }
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
