/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:18:40 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/27 13:18:40 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    ft_free_mat(char ***mat, int i)
{
    if (*mat)
    {
        while (i > 0)
            free ((*mat)[--i]);
        free (*mat);
        *mat = NULL;
    }
}

void    free_exit(data_struct *data_game, char **matrix, char **matrix2, 
    char *line)
{
    if (matrix)
        ft_free_mat(&matrix, data_game->aux_i);
    if (matrix2)
        ft_free_mat(&matrix2, data_game->aux_i);
    exit_error(data_game, data_game->error_code, line);
}
