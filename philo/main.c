/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/09 00:10:11 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	parse_args(char **args, t_conditions *conditions)
{
	int	i;

	i = 1;
	while (args[i + 1])
	{
		if (!args[i][0])
		{
			printf(R "Some conditions are missing\n" RE);
			return (1);
		}
		i++;
	}
	conditions->n_philo = ft_atoi(args[1]);
	conditions->t_die = ft_atoi(args[2]);
	conditions->t_eat = ft_atoi(args[3]);
	conditions->t_sleep = ft_atoi(args[4]);
	if (args[5] && args[5][0])
		conditions->n_eats = ft_atoi(args[5]);
	else
		conditions->n_eats = -1;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_conditions	conditions;

	if (argc < 5 || argc > 6)
	{
		printf(R "Invalid number of arguments\n" RE);
		return (EXIT_ERROR);
	}
	else
	{
		if (parse_args(argv, &conditions))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCES);
}