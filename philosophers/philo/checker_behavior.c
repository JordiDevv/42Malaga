/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_behavior.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 02:51:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/11 14:14:36 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	has_end(t_table *table, t_checker_utils *utils, int i)
{
	utils->act_time = get_time(0, "ACTUAL");
	utils->last_eating = table->philos[i].last_eating;
	if (utils->act_time - utils->last_eating >= table->conditions.t_die)
	{
		table->someone_dead = true;
		pthread_mutex_unlock(&table->check_mutex);
		mutex_print(&table->philos[i], DEATH_MSG);
		return (1);
	}
	if (table->philos[i].times_eaten >= table->conditions.n_eats)
		utils->sati_philo++;
	if (utils->sati_philo >= table->conditions.n_philo)
	{
		table->sati = true;
		pthread_mutex_unlock(&table->check_mutex);
		return (1);
	}
	return (0);
}

static int	check_end(t_table *table)
{
	int				i;
	t_checker_utils	utils;

	i = 0;
	utils.sati_philo = 0;
	while (i < table->conditions.n_philo)
	{
		if (has_end(table, &utils, i))
			return (1);
		i++;
	}
	return (0);
}

void	*checker_checks(void *arg)
{
	t_table	*table;

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
			break ;
		}
		pthread_mutex_unlock(&table->check_mutex);
	}
	return (NULL);
}
