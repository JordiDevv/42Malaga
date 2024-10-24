/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:04:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/20 03:04:30 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_sprite(t_data_struct *data_game, t_map_point cell,
	mlx_image_t *sprite, char c)
{
	data_game->map[cell.y][cell.x] = c;
	mlx_image_to_window(data_game->mlx, sprite, cell.x * 64, cell.y * 64);
}

static void	oso_turn(t_data_struct *data_game, t_map_point *oso_pos,
	int ind_move)
{
	draw_sprite(data_game, *oso_pos, data_game->textures.floor_img, '0');
	if (ind_move == 0
		&& data_game->map[oso_pos->y - 1][oso_pos->x] != 'M')
		oso_pos->y--;
	if (ind_move == 1
		&& data_game->map[oso_pos->y][oso_pos->x + 1] != 'M')
	{
		oso_pos->x++;
		flip_sprite(data_game, &data_game->textures.en_oso,
			&data_game->textures.en_oso_img, "textures/en_oso.png");
	}
	if (ind_move == 2
		&& data_game->map[oso_pos->y + 1][oso_pos->x] != 'M')
		oso_pos->y++;
	if (ind_move == 3
		&& data_game->map[oso_pos->y][oso_pos->x - 1] != 'M')
	{
		oso_pos->x--;
		flip_sprite(data_game, &data_game->textures.en_oso,
			&data_game->textures.en_oso_img, "textures/en_oso_l.png");
	}
}

static void	mantis_turn(t_data_struct *data_game, t_map_point *mantis_pos,
	int ind_move)
{
	draw_sprite(data_game, *mantis_pos, data_game->textures.floor_img, '0');
	if (ind_move == 0
		&& data_game->map[mantis_pos->y - 1][mantis_pos->x] != 'O')
		mantis_pos->y--;
	if (ind_move == 1
		&& data_game->map[mantis_pos->y][mantis_pos->x + 1] != 'O')
	{
		mantis_pos->x++;
		flip_sprite(data_game, &data_game->textures.en_mantis,
			&data_game->textures.en_mantis_img, "textures/en_mantis_r.png");
	}
	if (ind_move == 2
		&& data_game->map[mantis_pos->y + 1][mantis_pos->x] != 'O')
		mantis_pos->y++;
	if (ind_move == 3
		&& data_game->map[mantis_pos->y][mantis_pos->x - 1] != 'O')
	{
		mantis_pos->x--;
		flip_sprite(data_game, &data_game->textures.en_mantis,
			&data_game->textures.en_mantis_img, "textures/en_mantis.png");
	}
}

static int	can_move(t_data_struct *data_game, t_map_point en_pos, int ind_move)
{
	if ((ind_move == 0
			&& data_game->map[en_pos.y - 1][en_pos.x] != '1'
		&& data_game->map[en_pos.y - 1][en_pos.x] != 'C'
		&& data_game->map[en_pos.y - 1][en_pos.x] != 'E')
		|| (ind_move == 1
		&& data_game->map[en_pos.y][en_pos.x + 1] != '1'
		&& data_game->map[en_pos.y][en_pos.x + 1] != 'C'
		&& data_game->map[en_pos.y][en_pos.x + 1] != 'E')
		|| (ind_move == 2
		&& data_game->map[en_pos.y + 1][en_pos.x] != '1'
		&& data_game->map[en_pos.y + 1][en_pos.x] != 'C'
		&& data_game->map[en_pos.y + 1][en_pos.x] != 'E')
		|| (ind_move == 3
		&& data_game->map[en_pos.y][en_pos.x - 1] != '1'
		&& data_game->map[en_pos.y][en_pos.x - 1] != 'C'
		&& data_game->map[en_pos.y][en_pos.x - 1] != 'E'))
		return (1);
	return (0);
}

void	enemies_turn(t_data_struct *data_game)
{
	t_map_point	mantis_pos;
	t_map_point	oso_pos;
	int			ind_move;

	if (!locate_element(data_game->map, data_game->mapheight, &mantis_pos, 'M'))
		return ;
	if (!locate_element(data_game->map, data_game->mapheight, &oso_pos, 'O'))
		return ;
	ind_move = rand() % 4;
	if (can_move(data_game, mantis_pos, ind_move))
		mantis_turn(data_game, &mantis_pos, ind_move);
	draw_sprite(data_game, mantis_pos, data_game->textures.en_mantis_img,
		'M');
	ind_move = rand() % 4;
	if (can_move(data_game, oso_pos, ind_move))
		oso_turn(data_game, &oso_pos, ind_move);
	draw_sprite(data_game, oso_pos, data_game->textures.en_oso_img,
		'O');
	if ((mantis_pos.x == data_game->beg.x && mantis_pos.y == data_game->beg.y)
		|| (oso_pos.x == data_game->beg.x && oso_pos.y == data_game->beg.y))
	{
		mlx_close_window(data_game->mlx);
		ft_printf("They caught you\n");
	}
}
