/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_flow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/03 00:09:02 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ex_frstblock(char *full_rute, char **split_cmd, char **env)
{
	int 	pipe_fd[2];
	pid_t	pid;

    if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(STDOUT_FILENO, pipe_fd[1]);
		if (execve(full_rute, split_cmd, env) == -1)
			return (-1);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		return (pipe_fd[0]);
	}
}
