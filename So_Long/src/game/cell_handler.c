/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:48:38 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/18 13:48:38 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	void_cell(int i, int j, t_data_struct *data_game)
{
	data_game->map[i][j] = 'P';
	mlx_image_to_window(data_game->mlx, data_game->textures.floor_img,
		data_game->beg.x * 64, data_game->beg.y * 64);
	mlx_image_to_window(data_game->mlx, data_game->textures.player_img,
		j * 64, i * 64);
	if (data_game->exit == true)
	{
		data_game->map[data_game->beg.y][data_game->beg.x] = 'E';
		mlx_image_to_window(data_game->mlx, data_game->textures.exit_img,
			data_game->beg.x * 64, data_game->beg.y * 64);
		data_game->exit = false;
	}
	else
		data_game->map[data_game->beg.y][data_game->beg.x] = '0';
}

void	collect_cell(int i, int j, t_data_struct *data_game)
{
	data_game->collected++;
	data_game->map[i][j] = 'P';
	mlx_image_to_window(data_game->mlx, data_game->textures.floor_img,
		data_game->beg.x * 64, data_game->beg.y * 64);
	mlx_image_to_window(data_game->mlx, data_game->textures.player_img,
		j * 64, i * 64);
	if (data_game->exit == true)
	{
		data_game->map[data_game->beg.y][data_game->beg.x] = 'E';
		mlx_image_to_window(data_game->mlx, data_game->textures.exit_img,
			data_game->beg.x * 64, data_game->beg.y * 64);
		data_game->exit = false;
	}
	else
		data_game->map[data_game->beg.y][data_game->beg.x] = '0';
}

void	exit_cell(int i, int j, t_data_struct *data_game)
{
	if (data_game->collected == data_game->collects_total)
		mlx_close_window(data_game->mlx);
	data_game->exit = true;
	data_game->map[i][j] = 'P';
	mlx_image_to_window(data_game->mlx, data_game->textures.player_img,
		j * 64, i * 64);
	data_game->map[data_game->beg.y][data_game->beg.x] = '0';
	mlx_image_to_window(data_game->mlx, data_game->textures.floor_img,
		data_game->beg.x * 64, data_game->beg.y * 64);
}
