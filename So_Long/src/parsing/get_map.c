/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:44:19 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/17 18:44:19 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void init_data_rest(data_struct *data_game)
{
    int i;
    int j;

    data_game->moves = 0;
    data_game->collected = 0;
    data_game->exit = false;
    data_game->error_code = 0;
    i = 0;
    while (i < data_game->mapheight)
    {
        j = 0;
        while (data_game->map[i][j])
        {
            if (data_game->map[i][j] == 'C')
                data_game->collects_total++;
            j++;
        }
        i++;
    }
}

char    *clean_line(char *line)
{
    char   *new_line;
    int     line_len;

    if (!line)
        return (NULL);
    line_len = ft_strlen(line) - 2;
    new_line = malloc(line_len + 1);
    ft_strlcpy(new_line, line, line_len + 1);
    free (line);
    return (new_line);
}

static void parse_map(data_struct *data_game, char *line, int i)
{
    char    **temp;
    char    **temp_aux;

    temp = NULL;
    temp_aux = NULL;
    while (line)
    {
        i = 0;
        if (ft_strlen(line) != data_game->mapwidth)
            free_exit(data_game, temp, temp_aux, line);
        kind_realloc(data_game, &temp, &temp_aux, line);
        if (temp_aux)
            aux_copy(data_game, &temp_aux, &temp, line);
        else
            ft_strlcpy(temp[0], line, ft_strlen(line) + 1);
        kind_realloc(data_game, &temp_aux, &temp, line);
        while (i < data_game->mapheight)
        {
            ft_strlcpy(temp_aux[i], temp[i], ft_strlen(temp[i]) + 1);
            i++;
        }
        add_line(data_game, &line);
    }
    ft_free_mat(&temp_aux, data_game->mapheight);
    finish_parseo(data_game, temp);
}

static void map_to_matrix(data_struct *data_game)
{
    char    *line;
    int     i;
    int     height;

    data_game->error_code = 1;
    i = 0;
    line = get_next_line(data_game->fd);
    if (!line)
    {
        ft_printf("Error\nEl mapa está vacío o empieza en blanco\n");
        exit_error(data_game, 0, line);
    }
    line = clean_line(line);
    data_game->mapwidth = ft_strlen(line);
    data_game->mapheight = 1;
    parse_map(data_game, line, i);
    element_error(data_game);
    walls_error(data_game);
    path_error(data_game);
}

void    read_map(data_struct *data_game, char **argv)
{
    data_game->fd = open(argv[1], O_RDONLY);
    if (data_game->fd < 0)
    {
        ft_printf("Error\nEl fichero no se abrió correctamente\n");
        exit (-1);
    }
    map_to_matrix(data_game);
    init_data_rest(data_game);
    close(data_game->fd);
    data_game->fd = -1;
}
