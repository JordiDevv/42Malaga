/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/15 00:19:42 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_table *table)
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

int	init_philos(t_table *table)
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
		table->philos[i].left_fork = &table->forks[0]; //Hay que cambiar esto
		table->philos[i].left_fork = &table->forks[i];
        if (pthread_create(&table->philos[i].thread, NULL,
                philo_life, &table->philos[i]))
            return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
		i++;
	}
    return (EXIT_SUCCESS);
}

static int	init_table(t_table *table)
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
	// if (gettimeofday(&table->tv, NULL)) //int init para inicializar todos los filósofos a la vez, a -1. -> while (1) lock mutex init if (init 0) unlock mutex init break. Se comprueba una variable inicializadora dentro de un mutex, y el hilo checker es el que la inicializa, después de inicializar todos los filósofos. AHÍ es donde hay que coger el tiempo, para que esté bien sincronizado con el inicio de los hilos.
	// 	return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	// table->start_time = //Aquí el tiempo parseado
    return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_table	table;
	
	if (parse_args(argc, argv, &table.conditions))
		return (EXIT_ERROR);
	if (init_table(&table))
		return (EXIT_ERROR);
	//Hay que inicializar las estructuras y el flujo, sincronizando el tiempo de los hilos con
	//un start_time global, que está en table. A partir de ahí habrá que controlar que no todos
	//los filósofos quieran coger los tenedores al mismo tiempo de primeras, por lo que he visto
	//se suele forzar que empiecen los impares y mientras los demás piensen. El flujo debería
	//seguir con la comprobación del tiempo individual de cada uno con su tiempo de comida;
	//liberando tenedores y yendo a dormir. Los que puedan los cogerán y así sucesivamente.
	//Tenemos un comprobador de comidas, por si se pasa el argumento n_eats, y una variable
	//en table para que se verifique si alguien ha muerto. Habrá que investigar ese hilo extra
	//que checkea la muerte. Por último una función que se encargue de gestionar el mutex para
	//printear que está en el table. Por lo demás creo que es toda la idea general del programa.
	pthread_mutex_lock(&table.init_mutex);
	table.init = true;
	pthread_mutex_unlock(&table.init_mutex);
	for (int i = 0; i < table.conditions.n_philo; i++)
    	pthread_join(table.philos[i].thread, NULL);
	return (EXIT_SUCCESS);
}
