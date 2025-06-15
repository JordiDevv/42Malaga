/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/15 13:47:48 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	for (int i = 0; i < table.conditions.n_philo; i++)
		pthread_join(table.philos[i].thread, NULL);
	return (EXIT_SUCCESS);
}
