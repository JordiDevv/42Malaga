/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:13:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/09 23:50:37 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	out_of_range(char *n, char *range)
{
	if (ft_strlen(n) > ft_strlen(range))
		return (EXIT_ERROR);
	if (ft_strncmp(n, range, ft_strlen(range)) > 0)
		return (EXIT_ERROR);
	return (0);
}

static int	valid_args(char **args)
{
	int	i;
	int	args_flag;

	i = 0;
	args_flag = 0;
	while (args[i] && i < 6)
	{
		if (!args[i][0] || ft_isdigit(args[i]))
		{
			printf(R "Some conditions are missing or wrong\n" RE);
			return (EXIT_ERROR);
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
    if (conditions->n_philo < 1 || conditions->n_eats > INT_MAX)
    {
        printf(R "This is not a good amount of philosophers\n" RE);
        return (EXIT_ERROR);
    }
    if (conditions->t_die < 1 || conditions->t_die > INT_MAX)
    {
        printf(R "We all gotta die\n" RE);
        return (EXIT_ERROR);
    }
    if (conditions->t_eat < 1 || conditions->t_eat > INT_MAX)
    {
        printf(R "It's good to feed your brain, but either the stomach\n" RE);
        return (EXIT_ERROR);
    }
    if (conditions->t_sleep < 1 || conditions->t_sleep > INT_MAX)
    {
        printf(R "404 - Sleep not found\n" RE);
        return (EXIT_ERROR);
    }
    return (0);
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
		printf(R "Congratulations: Your philo have unlock the inmortality" RE);
		return (EXIT_ERROR);
	}
	return (0);
}
