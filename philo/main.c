/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/12 19:05:38 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_life(void *arg)
{

}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->conditions.n_philo)
	{
		table->philos[i].id = pthread_create(&table->philos[i].thread,
				NULL, philo_life, &table->philos[i]);
		
	}
}

static int	init_table(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL))
	{
		//destroy_mutex(table, MSSG);
		return (EXIT_ERROR);
	}
	if (gettimeofday(&table->tv, NULL))
	{
		//destroy_mutex(table, MSSG);
		return (EXIT_ERROR);
	}
	table->start_time = //Aquí el tiempo parseado
	init_philos(table);
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
	return (EXIT_SUCCES);
}
