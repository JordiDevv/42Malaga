/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:09:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/21 16:22:44 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    aux_ex_cmd1(t_data *program_data, int argc)
{
    close(program_data->pipe[0][1]);
    if (argc == 5)
        dup2(program_data->fds[1], STDOUT_FILENO);
    else
    {
        close(program_data->fds[1]);
        dup2(program_data->pipe[1][1], STDOUT_FILENO);
    }
}

static void	input_heredoc(t_data *program_data)
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

void    init_heredoc(t_data *program_data, char **argv, int argc)
{
    program_data->here_doc = true;
    program_data->limiter = malloc(ft_strlen(argv[2]) + 1);
    if (!program_data->limiter)
    {
        perror("Error allocating limiter");
        free_exit(program_data);
    }
    ft_strlcpy(program_data->limiter, argv[2], ft_strlen(argv[2]) + 1);
    program_data->fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT
		| O_APPEND, S_IRUSR | S_IWUSR);
    if (program_data->fds[1] < 0)
	{
		perror("Error opening or creating the second file");
		free_exit(program_data);
	}
    input_heredoc(program_data);
}
