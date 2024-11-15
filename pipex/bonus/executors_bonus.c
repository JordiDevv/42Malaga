/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:15:32 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/15 12:30:41 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void input_heredoc(t_data *program_data)
{
    char *line;

    while (1)
    {
		//Parece que se ha logrado una implementación adecuada para here_doc. Se ha \
			creado un puntero char en la estructura t_data llamado limiter que se \
			encarga de almacenar el delimitador que se ha pasado como argumento. \
			Se ha creado un bucle while que se ejecuta mientras se cumpla la condición \
			de que la variable line no sea igual a la variable limiter. Se ha adecuado el \
			resto del código para que funcione correctamente con esta implementación.
		//Hay que cambiar la función readline algo que podamos usar: la función \
			"get_next_line" podría ser una buena opción. Habría que comprobar también si \
			funciona correctamente con el flujo actual o si es necesario habría que \
			adaptarlo.
		//Además también se ha arreglado un pequeño error que había al pasar un primer \
			fichero inválido.
        line = readline("heredoc> ");
        if (!ft_strncmp(line, program_data->limiter, 
            ft_strlen(program_data->limiter)))
            break ;
        write(program_data->pipe[0][1], line, ft_strlen(line));
        write(program_data->pipe[0][1], "\n", 1);
        free(line);
    }
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
