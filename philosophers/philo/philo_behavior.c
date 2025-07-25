/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/11 14:15:37 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	coor_init(t_philo *philo)
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

static int	end_program(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->check_mutex);
	if (philo->table->someone_dead
		|| philo->times_eaten >= philo->table->conditions.n_eats)
	{
		pthread_mutex_unlock(&philo->table->check_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->check_mutex);
	return (0);
}

static int	to_eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		mutex_print(philo, FORK_MSG);
		pthread_mutex_lock(philo->right_fork);
		mutex_print(philo, FORK_MSG);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		mutex_print(philo, FORK_MSG);
		pthread_mutex_lock(philo->left_fork);
		mutex_print(philo, FORK_MSG);
	}
	if (end_program(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	mutex_print(philo, EAT_MSG);
	return (0);
}

static void	philo_routine(t_philo *philo)
{
	while (1)
	{
		if (to_eat(philo))
			break ;
		pthread_mutex_lock(&philo->table->check_mutex);
		philo->times_eaten++;
		philo->last_eating = get_time(0, "ACTUAL");
		pthread_mutex_unlock(&philo->table->check_mutex);
		ft_usleep(philo, philo->table->conditions.t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_usleep(philo, 1);
		if (end_program(philo))
			break ;
		mutex_print(philo, SLEEP_MSG);
		ft_usleep(philo, philo->table->conditions.t_sleep);
		if (end_program(philo))
			break ;
		mutex_print(philo, THINK_MSG);
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	coor_init(philo);
	philo->last_eating = get_time(0, "ACTUAL");
	pthread_mutex_lock(&philo->table->check_mutex);
	if (philo->table->conditions.n_philo < 2)
	{
		pthread_mutex_unlock(&philo->table->check_mutex);
		mutex_print(philo, FORK_MSG);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->table->check_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo, 10);
	philo_routine(philo);
	return (NULL);
}
