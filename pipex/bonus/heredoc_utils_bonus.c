/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:09:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/21 00:23:13 by jsanz-bo         ###   ########.fr       */
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

void	input_heredoc(t_data *program_data)
{
    char *line;

    while (1)
    {
        write(1, "> ", 2);
        line = get_next_line(0);
        if (!ft_strncmp(line, program_data->limiter,
            ft_strlen(program_data->limiter)))
            break ;
        write(program_data->pipe[0][1], line, ft_strlen(line));
        free(line);
    }
    if (line)
        free(line);
    close(program_data->pipe[0][1]);
    dup2(program_data->pipe[0][0], STDIN_FILENO);
    close(program_data->pipe[0][0]);
}
