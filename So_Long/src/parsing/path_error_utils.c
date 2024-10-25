/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:42:54 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/14 01:42:54 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	locate_element(char **map, int height, t_map_point *p, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				p->x = j;
				p->y = i;
				flag++;
			}
			j++;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

char	**copy_map(char **ori_map, int n_lines, int l_line)
{
	int		i;
	char	**new_map;

	new_map = malloc(n_lines * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < n_lines)
	{
		new_map[i] = malloc(l_line + 1 * sizeof(char));
		if (!new_map[i])
		{
			ft_free_mat(&new_map, i);
			return (NULL);
		}
		ft_strlcpy(new_map[i], ori_map[i], ft_strlen(ori_map[i]) + 1);
		i++;
	}
	return (new_map);
}

static void	fill(char **map, int new_x, int new_y, t_map_point size)
{
	t_map_point	new_p;
	int			mapwidth;
	int			mapheight;

	mapwidth = size.x;
	mapheight = size.y;
	if (new_x >= 0 && new_x < mapwidth && new_y >= 0
		&& new_y < mapheight && (map[new_y][new_x] == '0'
		|| map[new_y][new_x] == 'C' || map[new_y][new_x] == 'E'))
	{
		new_p.x = new_x;
		new_p.y = new_y;
		flood_fill(map, new_p, mapwidth, mapheight);
	}
}

void	flood_fill(char **map, t_map_point p, int mapwidth, int mapheight)
{
	t_map_point	new_p;
	t_map_point	size;

	size.x = mapwidth;
	size.y = mapheight;
	map[p.y][p.x] = 'F';
	fill(map, p.x - 1, p.y, size);
	fill(map, p.x + 1, p.y, size);
	fill(map, p.x, p.y - 1, size);
	fill(map, p.x, p.y + 1, size);
}

int	fill_checker(char **map, int mapheight)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapheight)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'F' && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
