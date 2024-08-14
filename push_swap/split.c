/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:11:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/09 00:41:35 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	next_word = malloc(len * sizeof(char) + 1);
	if (next_word == NULL)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		words_counter;
	int		i;

	i = 1;
	if (!str)
		return (NULL);
	words_counter = ft_strparr(str, c);
	if (!words_counter)
		return (NULL);
	arr = malloc((words_counter-- + 2) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = malloc(sizeof(char));
	if (arr[0] == NULL)
		return (NULL);
	arr[0][0] = '\0';
	while (words_counter-- >= 0)
		arr[i++] = get_next_word(str, c);
	arr[i] = NULL;
	return (arr);
}
