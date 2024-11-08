/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:55:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/09 00:13:37 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	prepare_aux(t_data *program_data, char *cmd)
{
    if (program_data->full_rute)
        free(program_data->full_rute);
    if (program_data->split_cmd)
        free_mat(program_data->split_cmd);
    program_data->split_cmd = ft_split(cmd, ' ');
	if(!program_data->split_cmd)
	{
		ft_printf("Error spliting the comand");
		free_exit(program_data);
	}
}

void	valid_cmd(char *cmd, t_data *program_data)
{
	int		i;

	i = 0;
	prepare_aux(program_data, cmd);
	while (program_data->path_mat[i])
	{
		program_data->full_rute = strmcat(3, 0, program_data->path_mat[i], "/",
			program_data->split_cmd[0]);
		if(!program_data->full_rute)
		{
			ft_printf("Error concatenating the full rute");
			free_exit(program_data);
		}
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