/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:12:53 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/26 01:12:53 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*beg;
	char	*new_storage;
	int		subs;

	beg = ft_strchr(storage, '\n');
	if (!beg)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		subs = beg - storage + 1;
	if (!storage[subs])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, subs, ft_strlen(storage) - subs);
	ft_free(&storage);
	if (!new_storage)
		new_storage = NULL;
	return (new_storage);
}

char	*get_line(char *storage)
{
	char	*line;
	char	*end;
	int		len;

	end = ft_strchr(storage, '\n');
	len = end - storage + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_storage(int fd, char *storage)
{
	char	*buff;
	int		buff_size;

	buff_size = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free(&storage));
	buff[0] = 0;
	while (buff_size > 0 && !ft_strchr(buff, '\n'))
	{
		buff_size = read (fd, buff, BUFFER_SIZE);
		if (buff_size > 0)
		{
			buff[buff_size] = '\0';
			storage = ft_strjoin(storage, buff);
		}
	}
	free(buff);
	if (buff_size < 0)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !ft_strchr(storage[fd], '\n')))
		storage[fd] = get_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = get_line(storage[fd]);
	if (!line)
		return (NULL);
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
