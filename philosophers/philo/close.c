/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:42:57 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/06 18:49:40 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_all(t_table *table, char *error_msg)
{
	pthread_join(table->checker, NULL);
	return (free_philos(table, error_msg, table->conditions.n_philo, 5));
}

int	free_forks(t_table *table, char *error_msg, int n, int flag)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	return (free_rsrcs(table, error_msg, flag));
}

int	free_philos(t_table *table, char *error_msg, int n, int flag)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (free_forks(table, error_msg, table->conditions.n_philo, flag));
}

int	free_rsrcs(t_table *table, char *error_msg, int flag)
{
	if (flag > 0)
		pthread_mutex_destroy(&table->init_mutex);
	if (flag > 1)
		pthread_mutex_destroy(&table->check_mutex);
	if (flag > 2)
		pthread_mutex_destroy(&table->print_mutex);
	if (flag > 3)
	{
		free(table->forks);
	}
	if (flag > 4)
		free(table->philos);
	if (table->sati)
		printf(G "%s" RE, error_msg);
	else if (table->someone_dead)
	{
		error_msg = BAD_END;
		printf(Y "%s" RE, error_msg);
	}
	else
		printf(R "%s" RE, error_msg);
	return (1);
}
