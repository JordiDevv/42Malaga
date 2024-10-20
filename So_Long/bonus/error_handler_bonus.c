/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:13 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/05 15:54:13 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    exit_error(data_struct *data_game, int error_code, char *line)
{
    if (line)
        free (line);
    if (error_code == 1)
        ft_printf("Error\nLas dimensiones del mapa no son correctas\n");
    if (error_code == 2)
        ft_printf("Error\nEl mapa no está completamente rodeado por muros\n");
    if (error_code == 3)
        ft_printf("Error\nEl mapa contiene elementos \033[3milegales\033[0m\n");
    if (error_code == 4)
        ft_printf("Error\nSolo puedes empezar y salir por un único sitio\n");
    if (error_code == 5)
        ft_printf("Error\nAl mapa le faltan elementos\n");
    if (error_code == 6)
        ft_printf("Error\nNo se puede salir de este mapa!\n");
    close(data_game->fd);
    if (data_game->map)
        ft_free_mat(&data_game->map, data_game->mapheight);
    exit (-1);
}

void    walls_error(data_struct *data_game)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (data_game->map[0][j])
    {
        if (data_game->map[0][j] != '1')
            exit_error(data_game, 2, NULL);
        j++;
    }
    while (i < data_game->mapheight - 1)
    {
        if (data_game->map[i][0] != '1' ||
            data_game->map[i][data_game->mapwidth - 1] != '1')
            exit_error(data_game, 2, NULL);
        i++;
    }
    j = 0;
    while (data_game->map[i][j])
    {
        if (data_game->map[i][j] != '1')
            exit_error(data_game, 2, NULL);
        j++;
    }
}

static int element_counter(data_struct *data_game, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < data_game->mapheight)
    {
        j = 0;
        while (data_game->map[i][j])
        {
            if (data_game->map[i][j] == c)
                count++;
            if (data_game->map[i][j] != 'P' && data_game->map[i][j] != 'E' &&
                data_game->map[i][j] != '1' && data_game->map[i][j] != '0' &&
                data_game->map[i][j] != 'C' && data_game->map[i][j] != 'M' &&
                data_game->map[i][j] != 'O')
                exit_error(data_game, 3, NULL);
            j++;
        }
        i++;
    }
    return (count);
}

void    element_error(data_struct *data_game)
{
    if (element_counter(data_game, 'P') > 1 || 
        element_counter(data_game, 'E') > 1 )
        exit_error(data_game, 4, NULL);
    if (!(element_counter(data_game, 'P')) ||
        !(element_counter(data_game, 'E')) ||
        !(element_counter(data_game, 'C')))
        exit_error(data_game, 5, NULL);
}


void    path_error(data_struct *data_game)
{
    char        **fill_map;
    map_point   p;

    ft_memset(&p, 0, sizeof(map_point));
    locate_element(data_game->map, data_game->mapheight, &p, 'P');
    data_game->beg = p;
    fill_map = copy_map(data_game->map, data_game->mapheight, 
        data_game->mapwidth);
    if (!fill_map)
        free_exit(data_game, NULL, NULL, NULL);
    flood_fill(fill_map, p, data_game->mapwidth, data_game->mapheight);
    if (fill_checker(fill_map, data_game->mapheight))
        exit_error(data_game, 6, NULL);
}
