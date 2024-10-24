/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:45:55 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/20 23:45:55 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_moves(t_data_struct *data_game)
{
	char	*n;

	mlx_image_to_window(data_game->mlx, data_game->textures.floor_img, 0, 0);
	mlx_image_to_window(data_game->mlx, data_game->textures.wall_img, 0, 0);
	n = ft_itoa(data_game->moves);
	mlx_put_string(data_game->mlx, n, 15, 15);
	free (n);
}

void	flip_sprite(t_data_struct *data_game, mlx_texture_t **texture,
	mlx_image_t **sprite, char *rute)
{
	mlx_delete_texture(*texture);
	mlx_delete_image(data_game->mlx, *sprite);
	*texture = mlx_load_png(rute);
	*sprite = mlx_texture_to_image(data_game->mlx, *texture);
	mlx_image_to_window(data_game->mlx, data_game->textures.player_img,
		data_game->beg.x * 64, data_game->beg.y * 64);
}
