/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/09 00:14:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	if (mat)
	{
		while (i > 0)
			free ((mat)[--i]);
		free (mat);
		mat = NULL;
	}
}

void	free_exit(t_data *program_data)
{
	if (program_data->fds[0] > 0)
		close(program_data->fds[0]);
	if (program_data->fds[1])
		close(program_data->fds[1]);
	if (program_data->pipe[0])
		close(program_data->pipe[0]);
	if (program_data->pipe[1])
		close(program_data->pipe[1]);
	if (program_data->path_mat)
		free_mat(program_data->path_mat);
	if (program_data->full_rute)
		free(program_data->full_rute);
	if (program_data->split_cmd)
		free_mat(program_data->split_cmd);
	exit (EXIT_FAILURE);
}
