/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:00:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/01 20:17:44 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->conditions.n_philo);
	if (!table->forks)
		return (free_rsrcs(table, INIT_ERR, 3));
	while (i < table->conditions.n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (free_forks(table, FORKS_ERR, i + 1, 4));
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	ref_forks(t_table *table, int i, int n_forks)
{
	table->philos[i].right_fork = &table->forks[i];
	if (i == 0)
	{
		table->philos[i].left_fork = &table->forks[n_forks - 1];
		if (i == n_forks - 1)
			table->philos[i].left_fork = NULL;
	}
	else
		table->philos[i].left_fork = &table->forks[i - 1];
}

static int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->conditions.n_philo);
	if (!table->philos)
		return (free_forks(table, PHILO_ERR, table->conditions.n_philo, 4));
	while(i < table->conditions.n_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].last_eating = get_time(0, "ACTUAL");
		table->philos[i].times_eaten = 0;
		ref_forks(table, i, table->conditions.n_philo);
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_life, &table->philos[i]))
			return (free_philos(table, PHILO_ERR, i + 1, 5));
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	init_checker(t_table *table)
{
	if (pthread_create(&table->checker, NULL, checker_checks, table))
			return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	return (0);
}

int	init_table(t_table *table)
{
	table->init = false;
	if (pthread_mutex_init(&table->init_mutex, NULL))
		return (EXIT_ERROR);
	table->someone_dead = false;
	if (pthread_mutex_init(&table->death_mutex, NULL))
		return (free_rsrcs(table, INIT_ERR, 1));
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (free_rsrcs(table, INIT_ERR, 2));
	if (init_forks(table))
		return (EXIT_ERROR);
	if (init_philos(table))
		return (EXIT_ERROR);
	if (init_checker(table))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	return (EXIT_SUCCESS);
}
