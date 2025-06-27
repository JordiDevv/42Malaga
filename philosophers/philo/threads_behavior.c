/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/27 20:45:26 by jsanz-bo         ###   ########.fr       */
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
			pthread_mutex_unlock(&philo->table->init_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->init_mutex);
	}
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	coor_init(philo);
	philo->time_on_action = get_time(philo->table->start_time, "DIF");
	if (philo->id % 2 == 0)
		ft_usleep(100);
	pthread_mutex_lock(philo->left_fork);
	printf("OK\n");
	pthread_mutex_lock(philo->right_fork);
	//printf(G "%ld: philo %d is eating\n" RE, get_time(philo->table->start_time, "DIF"), philo->id);
	ft_usleep(philo->table->conditions.t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	//Metemos un condicional para que los filósofos impares empiecen por el tenedor de la derecha y los pares por su izquierda e.g. Hay que investigar si no da problemas con el primero y el último en caso de ser impares y pares.
	//printf(G "%d se inició correctamente en %ld\n" RE, philo->id, philo->time_on_action);//Hay que borrar esto
	return (NULL);
}

void	*checker_checks(void *arg)
{
	t_table *table;
	table = (t_table *)arg;
	pthread_mutex_lock(&table->init_mutex);
	table->init = true;
	if (gettimeofday(&table->tv, NULL))
		return (NULL/*destroy_mutex(table, MSSG);*/);
	table->start_time = table->tv.tv_sec * 1000 + table->tv.tv_usec / 1000;
	pthread_mutex_unlock(&table->init_mutex);
	return (NULL);
}
