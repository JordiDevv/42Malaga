/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:15:32 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/15 18:05:41 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void input_heredoc(t_data *program_data)
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
    //Parece que el programa funciona bien con todas las implementaciones del bonus pero \
        cuando pasamos como primer comando "cat" se mantiene en el bucle de entrada: hay \
        que ver cómo solucionar esto. Quizás cerrando el pipe[0][1] después de escribir.
    close(program_data->fds[1]);
    close(program_data->fds[0]);
    dup2(program_data->pipe[0][0], STDIN_FILENO);
    dup2(program_data->pipe[1][1], STDOUT_FILENO);
}

void ex_nextcmd(t_data *program_data, int i)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
        free_exit(program_data);
    if (pid == 0)
    {
        close(program_data->pipe[i][0]);
        close(program_data->pipe[i - 1][1]);
        close(program_data->fds[1]);
        dup2(program_data->pipe[i - 1][0], STDIN_FILENO);
        dup2(program_data->pipe[i][1], STDOUT_FILENO);
        if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
            free_exit(program_data);
    }
    else
    {
        waitpid(pid, NULL, 0);
        close(program_data->pipe[i - 1][0]);
		close(program_data->pipe[i][1]);
    }
}

void ex_finalcmd(t_data *program_data, int i)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
        free_exit(program_data);
    if (pid == 0)
    {
        dup2(program_data->pipe[i - 1][0], STDIN_FILENO);
        dup2(program_data->fds[1], STDOUT_FILENO);
        if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
            free_exit(program_data);
    }
    else
    {
        waitpid(pid, NULL, 0);
        close(program_data->pipe[i - 1][0]);
    }
}

void	ex_cmd1(t_data *program_data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
        if(program_data->here_doc)
            input_heredoc(program_data);
        else
        {
            close(program_data->fds[1]);
            close(program_data->pipe[0][0]);
            dup2(program_data->fds[0], STDIN_FILENO);
            dup2(program_data->pipe[0][1], STDOUT_FILENO);
        }
		if (program_data->cmd1)
		{
			if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
				free_exit(program_data);
		}
	}
	else
		waitpid(pid, NULL, 0);
}
