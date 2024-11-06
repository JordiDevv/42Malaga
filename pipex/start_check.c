/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/06 17:38:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int check_sndblock(char *, char **path_mat, int err_flag, int in_fd)
{
    int		fd2;
    
    fd2 = -1;
    if (!valid_cmd(args[3], path_mat))
	{
		ft_printf("%s: command not found\n", args[3]);
		err_flag++;
	}
	if (access(args[4], F_OK))
	{
		fd2 = open(args[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd2 < 0)
		{
			perror("Fallo al intentar crear el fichero objetivo");
            //Hay que liberar path_mat
			exit(EXIT_FAILURE);
		}
	}
    //Va a tocar otra mini-función para finalizar el flujo
    if (err_flag)
	{
		if (fd2 >= 0)
			close(fd2);
        //Hay que liberar path_mat
		exit(EXIT_FAILURE);
	}
    //Hay que liberar path_mat
}

void	check_args(char **args)
{
	char	**path_mat;
	int		pipe_fd[2];

	path_mat = get_path();
	else
	{
		if (pipe(pipe_fd) == -1)
			return (-1); //Hay que liberar path_mat
		valid_cmd(args[2], path_mat, pipe_fd, 1);
	}
	if (access(args[4], F_OK))
	{
		fds[1]
		= open(args[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fds[1] < 0)
		{
			perror("Error creating the target file");
            //Hay que liberar path_mat
			exit(EXIT_FAILURE);
		}
	}
}

//El err_flag quizás no haga falta, porque simplemente va imprimiendo errores, pero \
	sigue el flujo
//Quizás se podría crear el pipe en check_args y reutilizar las funciones que gestionan \
	la ejecución del comando; aunque en caso del segundo bloque, el segundo fichero se \
	debe crear... Habrá que darle una vuelta

//Es posible que sea un mejor enfoque checkear primero los ficheros, asignando el pipe \
	en consecuencia y abriendo según qué archivos. Es decir, una función que: compruebe \
	el fichero 1, y, en caso de existir lo abra y le asigne el pipe de lectura; y, por \
	lado, intente abrir el segundo fichero y, en caso de no existir, lo cree. Habría que \
	analizar cómo incorporar el flujo de ejecuciones.
//Hay que investigar la ejecución (o no) del primer comando, en caso de que el primer \
	fichero no exista. Cancela su ejecución y simplemente se ejecuta el segundo sobre \
	la entrada estándar, o se ejecuta este primero sobre la entrada estándar, pasando \
	estos datos por el pipe?

