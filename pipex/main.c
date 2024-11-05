/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:20:47 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/05 16:18:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(t_data *program_data)
{
	int		i;
	char	*path;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "PATH=", 5))
		{
			path = malloc(ft_strlen(environ[i]) - 4);
			if (!path)
			{
				perror("Error allocating path");
				exit (EXIT_FAILURE);
			}
			ft_strlcpy(path, environ[i] + 5, ft_strlen(environ[i]) - 4);
		}
		i++;
	}
	program_data->path_mat = ft_split(path, ':');
	free(path);
}

static int	*create_pipe(t_data *program_data)
{
	if (pipe(program_data->pipe) < 0)
	{
		perror("Error creating the pipe");
		exit (EXIT_FAILURE);
	}
}

static int	*open_files(char **args, t_data *program_data)
{
	if (access(args[1], F_OK))
		ft_printf("-bash: %s: %s\n", args[1], strerror(errno));
	else
	{
		program_data->fds[0] = open(args[1], O_RDONLY);
		if (program_data->fds[0] < 0)
		{
			perror("Error opening the first file despite was found");
			exit (EXIT_FAILURE);
		}
		program_data->file1 = 1;
	}
	program_data->fds[1] = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (program_data->fds[1] < 0)
	{
		perror("Error opening or creating the second file");
		if (program_data->fds[0] > 0)
			close(program_data->fds[0]);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_data	program_data;

	if (argc != 5)
	{
		ft_printf("The program expects \033[3mexactly\033[0m 4 arguments");
		ft_printf("\n");
		return (1);
	}
	ft_bzero(&program_data, sizeof(t_data));
	open_files(argv, &program_data);
	create_pipe(&program_data);
	get_path(&program_data);
	if (program_data.file1)
		//Aquí deberíamos llamar a valid_cmd, y este, en caso de encontrar el comando, \
			debería establecer cmd1 en 1, para, más tarde, si, o file1 o cmd1, son falsos \
			cerrar inmediatamente la salida del pipe, y que el siguiente proceso lea de \
			una entrada vacía. También, en caso de encontrar cmd, deberá seguir el flujo \
			de ejecución que teníamos planteado, aunque habrá que revisarlo con la nueva \
			lógica.
	//Parece que hemos encontrado un flujo bastante coherente y limpio. A partir de aquí \
		ya deberíamos comprobar los comando y crear los procesos hijos para redirigir: En \
		uno la entrada estándar a nuestro fichero de lectura, y la salida estándar al \
		extremo de escritura de nuestro pipe; y viceversa.
	check_args(argv);
	return (0);
}
