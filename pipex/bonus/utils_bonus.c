/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:09:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/15 17:30:08 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    init_limiter(t_data *program_data, char **argv)
{
    program_data->here_doc = true;
    program_data->limiter = malloc(ft_strlen(argv[2]) + 1);
    if (!program_data->limiter)
    {
        perror("Error allocating limiter");
        free_exit(program_data);
    }
    ft_strlcpy(program_data->limiter, argv[2], ft_strlen(argv[2]) + 1);
}
