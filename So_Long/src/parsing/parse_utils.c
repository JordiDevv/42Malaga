/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:12:47 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/27 13:12:47 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    kind_realloc(data_struct *data_game, char ***matrix, char ***matrix2,
    char *line)
{
    int i;

    if (*matrix)
        ft_free_mat(matrix, data_game->mapheight - 1);
    *matrix = malloc(data_game->mapheight * sizeof(char *));
    if (*matrix == NULL)
    {
        data_game->error_code = 0;
        free_exit(data_game, *matrix, *matrix2, line);
    }
    i = 0;
    while (i < data_game->mapheight)
    {
        (*matrix)[i] = malloc(ft_strlen(line) + 1);
        if (!(*matrix)[i])
        {
            data_game->error_code = 0;
            data_game->aux_i = i;
            free_exit(data_game, *matrix, *matrix2, line);
        }
        i++;
    }
}

void    aux_copy(data_struct *data_game, char ***temp_aux, char ***temp, 
    char *line)
{
    int i;

    i = 0;
    while (i < data_game->mapheight - 1)
    {
        ft_strlcpy((*temp)[i], (*temp_aux)[i], ft_strlen((*temp_aux)[i]) + 1);
        i++;
    }
    ft_free_mat(&(*temp_aux), data_game->mapheight - 1);
    ft_strlcpy((*temp)[i], line, ft_strlen(line) + 1);
}

void    add_line(data_struct *data_game, char **line)
{
    free (*line);
    *line = get_next_line(data_game->fd);
    if (!(*line))
        return ;
    if (ft_strchr(*line, '\n') || ft_strchr(*line, '\r'))
    {
        *line = clean_line(*line);
    }
    if (*line)
        data_game->mapheight++;
}

void    finish_parseo(data_struct *data_game, char **temp)
{
    int i;
    int height;

    i = 0;
    height = data_game->mapheight;
    data_game->map = malloc(data_game->mapheight * sizeof(char *));
    while (--height >= 0)
        data_game->map[i++] = malloc(data_game->mapwidth + 1);
    i = 0;
    while (i < data_game->mapheight)
    {
        ft_strlcpy(data_game->map[i], temp[i], ft_strlen(temp[i]) + 1);
        i++;
    }
    while (i-- > 0)
        free (temp[i]);
    free (temp);
}
