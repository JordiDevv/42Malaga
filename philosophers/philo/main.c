/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:55:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/03 13:20:24 by jsanz-bo         ###   ########.fr       */
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
	if (table.sati)
	{
		write(1, "ENTRA SATI\n", 11);
		free_all(&table, SATI_END);
	}
	else
	{
		write(1, "ENTRA BAD\n", 10);
		free_all(&table, BAD_END);
	}
	return (EXIT_SUCCESS);
}
