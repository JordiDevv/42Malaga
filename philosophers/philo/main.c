/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/01 18:37:49 by jsanz-bo         ###   ########.fr       */
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
	//falta implementar la posibilidad de que el programa cierre si se llega al número de
	//comidas opcional y el flujo para cerrar en limpio el programa.
	for (int i = 0; i < table.conditions.n_philo; i++)
		pthread_join(table.philos[i].thread, NULL);
    pthread_join(table.checker, NULL);
	return (EXIT_SUCCESS);
}
