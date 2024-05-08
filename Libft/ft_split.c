/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:11:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/05/08 14:38:50 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	void	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

static size_t	ft_strparr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_do_split(char **a, char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	start;
	size_t	end;

	arr = a;
	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			end = start;
			while (s[end] && s[end] != c)
				end++;
			arr[i++] = ft_strndup(s + start, end - start);
			if (!arr[i - 1])
			{
				i = 0;
				while (arr[i])
					free (arr[i++]);
				free(arr);
				return (NULL);
			}
			start = end;
		}
		if (s[start])
			start++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_strparr(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_do_split(arr, s, c);
	return (arr);
}
