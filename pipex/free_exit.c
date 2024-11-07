/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/07 11:29:29 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		//Liberar matriz.
	exit (EXIT_FAILURE);
}

//Hay una función "ft_free_mat" en el proyecto so_long, que creo que debería funcionar\
	igual para liberar las matrices.