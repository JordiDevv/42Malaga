/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 02:51:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/03 19:13:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_end(t_table *table)
{
	int		i;
	long	last_eating;
	int		sati_philo;

    long    act;

	i = 0;
	sati_philo = 0;
	while (i < table->conditions.n_philo)
	{
        act = get_time(0, "ACTUAL");
		last_eating = table->philos[i].last_eating;
		if (act - last_eating >= table->conditions.t_die)
		{
            table->someone_dead = true;
			mutex_print(&table->philos[i], DEATH_MSG);
			return (1);
		}
		if (table->philos[i].times_eaten >= table->conditions.n_eats)
        {
			sati_philo++;
        }
		if (sati_philo >= table->conditions.n_philo)
		{
            table->sati = true;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*checker_checks(void *arg)
{
	t_table *table;
	table = (t_table *)arg;
	pthread_mutex_lock(&table->init_mutex);
	table->init = true;
	if (gettimeofday(&table->tv, NULL))
	{
		pthread_mutex_unlock(&table->init_mutex);
		free_all(table, TIME_ERR);
		return (NULL);
	}
	table->start_time = table->tv.tv_sec * 1000 + table->tv.tv_usec / 1000;
	pthread_mutex_unlock(&table->init_mutex);
	while (1)
	{
        pthread_mutex_lock(&table->check_mutex);
		if (check_end(table))
		{
            pthread_mutex_unlock(&table->check_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->check_mutex);
	}
	return (NULL);
}
