/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/29 22:36:25 by jsanz-bo         ###   ########.fr       */
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
		ft_usleep(philo, 100);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		mutex_print(philo, FORK_MSG);
		pthread_mutex_lock(philo->right_fork);
		mutex_print(philo, FORK_MSG);
		mutex_print(philo, EAT_MSG);
		ft_usleep(philo, philo->table->conditions.t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		mutex_print(philo, SLEEP_MSG);
		ft_usleep(philo, philo->table->conditions.t_sleep);
		mutex_print(philo, THINK_MSG);
	}
	//Ahora deberíamos meter esta lógica en un bucle y que lo compare con algún factor variante para escalarlo después
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
