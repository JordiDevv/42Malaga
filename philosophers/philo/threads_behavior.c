/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/15 17:39:25 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void  coor_init(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->init_mutex);
		if (philo->table->init)
		{
			printf(G "%d se inició correctamente\n" RE, philo->id);//Hay que borrar esto
			pthread_mutex_unlock(&philo->table->init_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->init_mutex);
	}
	return (0);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	coor_init(philo);
	return (NULL);
}

void	*checker_checks(void *arg)
{
	t_table *table;
	table = (t_table *)arg;
	pthread_mutex_lock(&table->init_mutex);
	table->init = true;
	pthread_mutex_unlock(&table->init_mutex);
	return (NULL);
}
