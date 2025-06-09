/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/09 18:33:23 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  valid_args(t_conditions *conditions)
{
    if (conditions->n_philo < 1 || conditions->n_eats > INT_MAX)
    {
        printf(R "This is not a good amount of philosophers\n" RE);
        return (1);
    }
    if (conditions->t_die < 1 || conditions->t_die > INT_MAX)
    {
        printf(R "We all gotta die\n" RE);
        return (1);
    }
    if (conditions->t_eat < 1 || conditions->t_eat > INT_MAX)
    {
        printf(R "It's good to feed your brain, but either the stomach\n" RE);
        return (1);
    }
    if (conditions->t_sleep < 1 || conditions->t_sleep > INT_MAX)
    {
        printf(R "404 - Sleep not found\n" RE);
        return (1);
    }
    return (0);
}

static int	parse_args(char **args, t_conditions *conditions)
{
	int	i;

	i = 1;
	while (args[i] && i < 6)
	{
		if (!args[i][0] || ft_isdigit(args[i]))
		{
			printf(R "Some conditions are missing or wrong\n" RE);
			return (1);
		}
		i++;
	}
    //Hacer un checker para comprobar el rango y la validez de los argumentos
	conditions->n_philo = ft_atoi(args[1]);
	conditions->t_die = ft_atoi(args[2]);
	conditions->t_eat = ft_atoi(args[3]);
	conditions->t_sleep = ft_atoi(args[4]);
	if (args[5] && args[5][0])
    {
        if (args[5][0] == '0')
        conditions->n_eats = ft_atoi(args[5]);
    }
	else
		conditions->n_eats = -1;
	return (valid_args(conditions));
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
