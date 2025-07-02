/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/02 11:31:14 by jsanz-bo         ###   ########.fr       */
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

static int	someone_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->check_mutex);
	if (philo->table->someone_dead)
	{
		pthread_mutex_unlock(&philo->table->check_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->check_mutex);
	return (0);
}

static void	philo_routine(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		if (someone_died(philo))
			break ;
		mutex_print(philo, FORK_MSG);
		pthread_mutex_lock(philo->right_fork);
		if (someone_died(philo))
			break ;
		mutex_print(philo, FORK_MSG);
		if (someone_died(philo))
			break ;
		mutex_print(philo, EAT_MSG);
		philo->times_eaten++;
		philo->last_eating = get_time(0, "ACTUAL");
		ft_usleep(philo, philo->table->conditions.t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (someone_died(philo))
			break ;
		mutex_print(philo, SLEEP_MSG);
		ft_usleep(philo, philo->table->conditions.t_sleep);
		if (someone_died(philo))
			break ;
		mutex_print(philo, THINK_MSG);
	}
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	coor_init(philo);
	philo->last_eating = get_time(0, "ACTUAL");
    if (philo->table->conditions.n_philo < 2)
    {
        mutex_print(philo, FORK_MSG);
        return (NULL);
    }
	if (philo->id % 2 == 0)
		ft_usleep(philo, 10);
	philo_routine(philo);
	return (NULL);
}
