/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:15:32 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/11 13:29:22 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ex_nextcmd(t_data *program_data, int *aux_pipe, int odd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		if(odd)
		{
			close(aux_pipe[0]);
			dup2(program_data->pipe[0], STDIN_FILENO);
			dup2(aux_pipe[1], STDOUT_FILENO);
		}
		else
		{
			close(program_data->pipe[0]);
			dup2(aux_pipe[0], STDIN_FILENO);
			dup2(program_data->pipe[1], STDOUT_FILENO);
		}
		if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
			free_exit(program_data);
	}
	else
		waitpid(pid, NULL, 0);
}

void	ex_finalcmd(t_data *program_data, int *aux_pipe, int odd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		free_exit(program_data);
	if (pid == 0)
	{
		if(!odd)
			dup2(aux_pipe[0], STDIN_FILENO);
		else
			dup2(program_data->pipe[0], STDIN_FILENO);
		//En la siguiente línea hay un bucle infinito
		dup2(program_data->fds[1], STDOUT_FILENO);
		if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
			free_exit(program_data);
	}
	else
	{
		close(program_data->pipe[1]);
		close(program_data->pipe[0]);
		close(aux_pipe[1]);
		close(aux_pipe[0]);
		waitpid(pid, NULL, 0);
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
		close(program_data->pipe[0]);
		dup2(program_data->fds[0], STDIN_FILENO);
		dup2(program_data->pipe[1], STDOUT_FILENO);
		if (program_data->cmd1)
		{
			if (execve(program_data->full_rute, program_data->split_cmd, environ) == -1)
				free_exit(program_data);
		}
	}
	else
		waitpid(pid, NULL, 0);
}
