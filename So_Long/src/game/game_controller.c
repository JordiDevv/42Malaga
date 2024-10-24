/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:13:51 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/15 23:13:51 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	free_images(t_data_struct *data_game)
{
	mlx_delete_texture(data_game->textures.wall);
	mlx_delete_texture(data_game->textures.floor);
	mlx_delete_texture(data_game->textures.exit);
	mlx_delete_texture(data_game->textures.collect);
	mlx_delete_texture(data_game->textures.player);
	mlx_delete_texture(data_game->textures.en_mantis);
	mlx_delete_texture(data_game->textures.en_oso);
	mlx_delete_image(data_game->mlx, data_game->textures.wall_img);
	mlx_delete_image(data_game->mlx, data_game->textures.floor_img);
	mlx_delete_image(data_game->mlx, data_game->textures.exit_img);
	mlx_delete_image(data_game->mlx, data_game->textures.collect_img);
	mlx_delete_image(data_game->mlx, data_game->textures.player_img);
	mlx_delete_image(data_game->mlx, data_game->textures.en_mantis_img);
	mlx_delete_image(data_game->mlx, data_game->textures.en_oso_img);
}

static void	get_images(t_data_struct *data_game)
{
	data_game->textures.wall = mlx_load_png("textures/wall.png");
	data_game->textures.floor = mlx_load_png("textures/floor.png");
	data_game->textures.player = mlx_load_png("textures/player.png");
	data_game->textures.en_mantis = mlx_load_png("textures/en_mantis.png");
	data_game->textures.en_oso = mlx_load_png("textures/en_oso.png");
	data_game->textures.collect = mlx_load_png("textures/collects.png");
	data_game->textures.exit = mlx_load_png("textures/exit.png");
	data_game->textures.wall_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.wall);
	data_game->textures.floor_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.floor);
	data_game->textures.player_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.player);
	data_game->textures.en_mantis_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.en_mantis);
	data_game->textures.en_oso_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.en_oso);
	data_game->textures.collect_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.collect);
	data_game->textures.exit_img = mlx_texture_to_image
		(data_game->mlx, data_game->textures.exit);
}

static void	display_image(t_data_struct *data_game, char c, int i, int j)
{
	if (c == '1')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.wall_img, j * 64, i * 64);
	if (c == 'C')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.collect_img, j * 64, i * 64);
	if (c == 'E')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.exit_img, j * 64, i * 64);
	if (c == 'P')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.player_img, j * 64, i * 64);
	if (c == 'M')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.en_mantis_img, j * 64, i * 64);
	if (c == 'O')
		mlx_image_to_window(data_game->mlx,
			data_game->textures.en_oso_img, j * 64, i * 64);
}

static void	display_map(t_data_struct *data_game)
{
	int	i;
	int	j;

	i = 0;
	while (i < data_game->mapheight)
	{
		j = 0;
		while (data_game->map[i][j])
		{
			mlx_image_to_window(data_game->mlx,
				data_game->textures.floor_img, j * 64, i * 64);
			display_image(data_game, data_game->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	start_game(t_data_struct *data_game)
{
	data_game->mlx = mlx_init(data_game->mapwidth * 64, data_game->mapheight
			* 64, "so_long", true);
	get_images(data_game);
	display_map(data_game);
	mlx_key_hook(data_game->mlx, key_controller, data_game);
	mlx_loop(data_game->mlx);
	if (data_game->collected == data_game->collects_total && data_game->exit)
		ft_printf("You won!\n");
	free_images(data_game);
	mlx_terminate(data_game->mlx);
}
