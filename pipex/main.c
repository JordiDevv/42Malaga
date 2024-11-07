/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:20:47 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/07 11:41:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	valid_cmd(char *cmd, t_data *program_data)
{
	int		i;

	i = 0;
	program_data->split_cmd = ft_split(cmd, ' ');
	if(!program_data->split_cmd)
	{
		ft_printf("Error spliting the comand");
		free_exit(program_data);
	}
	while (program_data->path_mat[i])
	{
		program_data->full_rute = strmcat(3, program_data->path_mat[i], "/",
			program_data->split_cmd[0]);
		if (!access(program_data->full_rute, X_OK))
		{
			if (program_data->step == 1)
				program_data->cmd1 = 1;
			else if (program_data->step == 2)
				program_data->cmd2 = 1;
			return ;
		}
		free(program_data->full_rute);
		i++;
	}
	ft_printf("%s: command not found\n", program_data->split_cmd[0]);
}

static void	get_path(t_data *program_data)
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
				free_exit(program_data);
			}
			ft_strlcpy(path, environ[i] + 5, ft_strlen(environ[i]) - 4);
		}
		i++;
	}
	if (!path)
	{
		ft_printf("Error: Path wasn't found.");
		free_exit(program_data);
	}
	program_data->path_mat = ft_split(path, ':');
	free(path);
}

static void	create_pipe(t_data *program_data)
{
	if (pipe(program_data->pipe) < 0)
	{
		perror("Error creating the pipe");
		free_exit(program_data);
	}
}

static void	open_files(char **args, t_data *program_data)
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
		free_exit(program_data);
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
	if (!program_data.path_mat)
	{
		ft_printf("Error spliting the path");
		free_exit(&program_data);
	}
	program_data.step = 1;
	if (program_data.file1)
		valid_cmd(argv[2], &program_data);
	//En algún punto deberíamos liberar "split_cmd", antes de reasignarlo.
	//"strmcat" no hace comprobación de malloc, y, por el mismo motivo, "valid_cmd" \
		tampoco: Las malditas 25 líneas
	ex_cmd1(&program_data);
	program_data.step = 2;
	valid_cmd(argv[3], &program_data);
	if (program_data.cmd2)
		ex_cmd2(&program_data);
		//Aquí deberíamos llamar a valid_cmd, y este, en caso de encontrar el comando, \
			debería establecer cmd1 en 1, para, más tarde, si, o file1 o cmd1, son falsos \
			cerrar inmediatamente la salida del pipe, y que el siguiente proceso lea de \
			una entrada vacía. También, en caso de encontrar cmd, deberá seguir el flujo \
			de ejecución que teníamos planteado, aunque habrá que revisarlo con la nueva \
			lógica.
	//Parece que va bastante bien, pero hay que arreglar la redirección de salida; La \
		salida de la ejecución del segundo comando, si es erróneo, va al segundo fichero. \
		Quizás deberíamos esperar a hacer la redirección de salida en la función "ex_cmd2".
	//Liberar todo el contenido program_data
	return (0);
}
