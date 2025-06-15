/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:13:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/10 09:30:23 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	out_of_range(char *n, char *range)
{
	if (ft_strlen(n) > ft_strlen(range))
		return (EXIT_ERROR);
	if (ft_strlen(n) == ft_strlen(range))
	{
		if (ft_strncmp(n, range, ft_strlen(range)) > 0)
			return (EXIT_ERROR);
	}
	return (0);
}

static int	valid_args(char **args)
{
	int	i;
	int	args_flag;

	i = 1;
	args_flag = 0;
	while (args[i] && i < 6)
	{
		if (!args[i][0] || ft_isdigit(args[i]))
		{
			printf(R "ARG %d: How am I supposed to work with this?\n" RE, i);
			args_flag++;
		}
		if (args[i][0] == '-')
		{
			printf(R "ARG %d: Be positive dude\n" RE, i);
			args_flag++;
		}
		if (out_of_range(args[i], I_MAX))
		{
			printf(R "ARG %d: This number is extremly high\n" RE, i);
			args_flag++;
		}
		i++;
	}
	return (args_flag);
}

static int  valid_conditions(t_conditions *conditions)
{
	int	con_flag;

	con_flag = 0;
    if (conditions->n_philo == 0)
    {
        printf(R "This is not a good amount of philosophers\n" RE);
        con_flag++;
    }
    if (conditions->t_die == 0)
    {
        printf(R "We all gotta die\n" RE);
        con_flag++;
    }
    if (conditions->t_eat == 0)
    {
        printf(R "It's good to feed your brain, but either the stomach\n" RE);
        con_flag++;
    }
    if (conditions->t_sleep == 0)
    {
        printf(R "404 - Sleep not found\n" RE);
        con_flag++;
    }
    return (con_flag);
}

int	parse_args(int argc, char **args, t_conditions *conditions)
{
	if (argc < 5 || argc > 6)
	{
		printf(R "Invalid number of arguments\n" RE);
		return (EXIT_ERROR);
	}
	if (valid_args(args))
		return (EXIT_ERROR);
	conditions->n_philo = ft_atoi(args[1]);
	conditions->t_die = ft_atoi(args[2]);
	conditions->t_eat = ft_atoi(args[3]);
	conditions->t_sleep = ft_atoi(args[4]);
	if (valid_conditions(conditions))
		return (EXIT_ERROR);
	if (args[5] && args[5][0])
		conditions->n_eats = ft_atoi(args[5]);
	else
		conditions->n_eats = INT_MAX;
	if (conditions->n_eats == 0)
	{
		printf(R "Congratulations: Philo have unlock the inmortality\n" RE);
		return (EXIT_ERROR);
	}
	return (0);
}
