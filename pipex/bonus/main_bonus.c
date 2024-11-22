/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:44:25 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/22 18:01:57 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	get_path(t_data *program_data)
{
	int		i;
	char	*path;

	i = -1;
	while (program_data->environ[++i])
	{
		if (!ft_strncmp(program_data->environ[i], "PATH=", 5))
		{
			path = malloc(ft_strlen(program_data->environ[i]) - 4);
			if (!path)
			{
				perror("Error allocating path");
				free_exit(program_data);
			}
			ft_strlcpy(path, program_data->environ[i] + 5,
				ft_strlen(program_data->environ[i]) - 4);
		}
	}
	if (!path)
	{
		ft_printf("Error: Path wasn't found.");
		free_exit(program_data);
	}
	program_data->path_mat = ft_split(path, ':');
	free(path);
}

static void	create_pipes(t_data *program_data, int n, int i)
{
	program_data->pipe = malloc(sizeof(int *) * (n + 1));
	if (!program_data->pipe)
	{
		perror("Error allocating the pipe");
		free_exit(program_data);
	}
	program_data->pipe[n] = NULL;
	while (i--)
	{
		program_data->pipe[i] = malloc(sizeof(int) * 2);
		if (!program_data->pipe[i])
		{
			perror("Error allocating the pipe");
			free_exit(program_data);
		}
	}
	while (++i < n)
	{
		if (pipe(program_data->pipe[i]) < 0)
		{
			perror("Error creating the pipe");
			free_exit(program_data);
		}
	}
}

static void	open_files(int argc, char **args, t_data *program_data)
{
	if (access(args[1], F_OK))
		ft_printf("-bash: %s: %s\n", args[1], strerror(errno));
	else
	{
		program_data->fds[0] = open(args[1], O_RDONLY);
		if (program_data->fds[0] < 0)
		{
			perror("Error opening the first file despite was found");
			free_exit(program_data);
		}
		program_data->file1 = 1;
	}
	program_data->fds[1] = open(args[argc - 1], O_WRONLY | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR);
	if (program_data->fds[1] < 0)
	{
		perror("Error opening or creating the second file");
		free_exit(program_data);
	}
}

static void	ex_flow(t_data *program_data, char **argv, int argc, int i)
{
	program_data->step = 1;
	if (program_data->file1)
		valid_cmd(argv[2], program_data);
	else if (program_data->here_doc)
		valid_cmd(argv[3], program_data);
	if ((program_data->file1 || program_data->here_doc) && program_data->cmd1)
		ex_cmd1(program_data, argc);
	if (program_data->here_doc && argc == 5)
		return ;
	program_data->step = 2;
	if (program_data->here_doc)
		i++;
	while (program_data->pipe[i])
	{
		valid_cmd(argv[i + 2], program_data);
		if (program_data->cmd2)
			ex_nextcmd(program_data, i);
		close(program_data->pipe[i][1]);
		program_data->cmd2 = 0;
		i++;
	}
	valid_cmd(argv[i + 2], program_data);
	if (program_data->cmd2)
		ex_finalcmd(program_data, i);
}

int	main(int argc, char **argv, char **env)
{
	t_data	program_data;

	if (!env[0] || argc < 5)
	{
		ft_printf("Error with enviroment or arguments\n");
		return (1);
	}
	program_data.environ = env;
	ft_bzero(&program_data, sizeof(t_data));
	create_pipes(&program_data, argc - 4, argc - 4);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		init_heredoc(&program_data, argv, argc);
	else
		open_files(argc, argv, &program_data);
	get_path(&program_data);
	if (!program_data.path_mat)
	{
		ft_printf("Error spliting the path");
		free_exit(&program_data);
	}
	ex_flow(&program_data, argv, argc, 1);
	free_exit(&program_data);
	return (0);
}
