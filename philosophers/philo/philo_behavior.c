/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/03 19:15:29 by jsanz-bo         ###   ########.fr       */
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

static int	end_program(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->check_mutex);
	if (philo->table->someone_dead || philo->table->sati)
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
		if (end_program(philo))
			break ;
		mutex_print(philo, FORK_MSG);
		pthread_mutex_lock(philo->right_fork);
		if (end_program(philo))
			break ;
		mutex_print(philo, FORK_MSG);
		if (end_program(philo))
			break ;
		mutex_print(philo, EAT_MSG);
		pthread_mutex_lock(&philo->table->check_mutex);
		philo->times_eaten++;
		pthread_mutex_unlock(&philo->table->check_mutex);
		philo->last_eating = get_time(0, "ACTUAL");
		ft_usleep(philo, philo->table->conditions.t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
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
	t_philo *philo;

	philo = (t_philo *)arg;
	coor_init(philo);
	philo->last_eating = get_time(0, "ACTUAL");
	pthread_mutex_lock(&philo->table->check_mutex);
    if (philo->table->conditions.n_philo < 2)
    {
        mutex_print(philo, FORK_MSG);
        pthread_mutex_unlock(&philo->table->check_mutex);
        return (NULL);
    }
	pthread_mutex_unlock(&philo->table->check_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo, 10);
	philo_routine(philo);
	return (NULL);
}
