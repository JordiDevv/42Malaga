/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:00:50 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/15 17:32:44 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->conditions.n_philo);
	if (!table->forks)
	{
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	}
	while (i < table->conditions.n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
		i++;
	}
	return (EXIT_SUCCESS);
}
static void	ref_forks(t_table *table, int i, int n_forks)
{
	table->philos[i].right_fork = &table->forks[i];
	if (i == 0)
	{
		table->philos[i].left_fork = &table->forks[n_forks - 1];
		if (i == n_forks - 1)
			table->philos[i].left_fork = NULL;//Aquí se debería gestionar el comportamiento que toque para que el único filósofo en la mesa muera de inanición por falta de tenedores
	}
	else
		table->philos[i].left_fork = &table->forks[i - 1];
}

static int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->conditions.n_philo);
	if (!table->philos)
	{
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	}
	while(i < table->conditions.n_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].time_on_action = 0;
		table->philos[i].times_eaten = 0;
		ref_forks(table, i, table->conditions.n_eats);
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_life, &table->philos[i]))
			return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
		i++;
	}
	return (EXIT_SUCCESS);
}
static int	init_checker(t_table *table)
{
	if (pthread_create(&table->checker, NULL, checker_checks, table))
			return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	return (0);
}

int	init_table(t_table *table)
{
	table->init = false;
	if (pthread_mutex_init(&table->init_mutex, NULL))
		return (EXIT_ERROR)/*destroy_mutex(table, MSSG);*/;
	table->someone_dead = false;
	if (pthread_mutex_init(&table->death_mutex, NULL))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	if (init_forks(table))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	if (init_philos(table))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	if (init_checker(table))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	// if (gettimeofday(&table->tv, NULL)) //int init para inicializar todos los filósofos a la vez, a -1. -> while (1) lock mutex init if (init 0) unlock mutex init break. Se comprueba una variable inicializadora dentro de un mutex, y el hilo checker es el que la inicializa, después de inicializar todos los filósofos. AHÍ es donde hay que coger el tiempo, para que esté bien sincronizado con el inicio de los hilos.
	// 	return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	// table->start_time = //Aquí el tiempo parseado
	return (EXIT_SUCCESS);
}
// El comportamiento del checker está incompleto, y entiendo que le falta
// un bucle (1) que compruebe constantemente si algún filósofo ha muerto y, en consecuencia, que bloquee a los demás hilos y printee él la muerte. Faltan las variables que se
// encargan de guardar el tiempo global(creo que deberían iniciarse en el checker); y por lo demás la función que se encarga de limpiar todo antes de salir.