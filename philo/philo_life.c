/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:03:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/14 20:43:52 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  coor_init(t_philo *philo)
{
	while (1)
	{
		if (pthread_mutex_lock(&philo->table->init_mutex))
			return (EXIT_ERROR)/*destroy_mutex(table, MSSG);*/;
		if (philo->table->init)
		{
			printf(G "%d se inició correctamente\n" RE, philo->id);
			if (pthread_mutex_unlock(&philo->table->init_mutex))
				return (EXIT_ERROR)/*destroy_mutex(table, MSSG);*/;
			break ;
		}
		if (pthread_mutex_unlock(&philo->table->init_mutex))
			return (EXIT_ERROR)/*destroy_mutex(table, MSSG);*/;
	}
    return (0);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (coor_init(philo))
		return (NULL);//(EXIT_ERROR)/*destroy_mutex(table, MSSG);*/;
    return (NULL);
}