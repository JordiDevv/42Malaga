/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:50:37 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/14 01:50:37 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int  verify_format(char *name)
{
    char    *format;

    format = ft_strrchr(name, '.');
    if (!format || ft_strcmp(format, ".ber"))
        return (1);
    return (0);
}

int main(int argc, char** argv)
{
    data_struct data_game;

    if (argc != 2)
    {
        ft_printf("Error\nEl programa espera únicamente, y solo, un mapa con \
extensión .ber\n");
        return (-1);
    }
    if (verify_format(argv[1]))
    {
        ft_printf("Error\nEl mapa no es de extensión .ber\n");
        return (-1);
    }
    ft_memset(&data_game, 0, sizeof(data_struct));
    read_map(&data_game, argv);
    start_game(&data_game);
    free_exit(&data_game, NULL, NULL, NULL);
    return (0);
}
//Habemus Jueguito! Ahora, a por el bonus