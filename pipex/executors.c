/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/07 10:08:48 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ex_cmd2(t_data *program_data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
		//Error creando el segundo proceso hijo
	if (pid == 0)
	{
		dup2(program_data->fds[1], STDOUT_FILENO);
		execve(program_data->full_rute, program_data->split_cmd, environ);
		//if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
			//Salimos liberando
	}
	else
	{
		close(program_data->pipe[0]);
		waitpid(pid, NULL, 0);
	}
}

void	ex_cmd1(t_data *program_data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
		//Error creando el primer proceso hijo
	if (pid == 0)
	{
		close(program_data->pipe[0]);
		dup2(program_data->fds[0], STDIN_FILENO);
		dup2(program_data->pipe[1], STDOUT_FILENO);
		if (program_data->cmd1)
		{
			execve(program_data->full_rute, program_data->split_cmd, environ);
			//if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
				//Salimos liberando
		}
	}
	else
	{
		close(program_data->pipe[1]);
		dup2(program_data->pipe[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
