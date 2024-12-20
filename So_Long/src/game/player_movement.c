/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:51:25 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/10/18 12:51:25 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	move_right(t_data_struct *data_game)
{
	int	i;
	int	j;

	i = data_game->beg.y;
	j = data_game->beg.x + 1;
	if (data_game->map[i][j] == '0')
		void_cell(i, j, data_game);
	if (data_game->map[i][j] == 'C')
		collect_cell(i, j, data_game);
	if (data_game->map[i][j] == 'E')
		exit_cell(i, j, data_game);
	if (data_game->map[i][j] != '1')
	{
		data_game->beg.x = j;
		data_game->moves++;
		ft_printf("%d\n", data_game->moves);
	}
}

static void	move_left(t_data_struct *data_game)
{
	int	i;
	int	j;

	i = data_game->beg.y;
	j = data_game->beg.x - 1;
	if (data_game->map[i][j] == '0')
		void_cell(i, j, data_game);
	if (data_game->map[i][j] == 'C')
		collect_cell(i, j, data_game);
	if (data_game->map[i][j] == 'E')
		exit_cell(i, j, data_game);
	if (data_game->map[i][j] != '1')
	{
		data_game->beg.x = j;
		data_game->moves++;
		ft_printf("%d\n", data_game->moves);
	}
}

static void	move_up(t_data_struct *data_game)
{
	int	i;
	int	j;

	i = data_game->beg.y - 1;
	j = data_game->beg.x;
	if (data_game->map[i][j] == '0')
		void_cell(i, j, data_game);
	if (data_game->map[i][j] == 'C')
		collect_cell(i, j, data_game);
	if (data_game->map[i][j] == 'E')
		exit_cell(i, j, data_game);
	if (data_game->map[i][j] != '1')
	{
		data_game->beg.y = i;
		data_game->moves++;
		ft_printf("%d\n", data_game->moves);
	}
}

static void	move_down(t_data_struct *data_game)
{
	int	i;
	int	j;

	i = data_game->beg.y + 1;
	j = data_game->beg.x;
	if (data_game->map[i][j] == '0')
		void_cell(i, j, data_game);
	if (data_game->map[i][j] == 'C')
		collect_cell(i, j, data_game);
	if (data_game->map[i][j] == 'E')
		exit_cell(i, j, data_game);
	if (data_game->map[i][j] != '1')
	{
		data_game->beg.y = i;
		data_game->moves++;
		ft_printf("%d\n", data_game->moves);
	}
}

void	key_controller(struct mlx_key_data key_data, void *param)
{
	t_data_struct		*data_game;

	data_game = param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(data_game->mlx);
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
		move_right(data_game);
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
		move_left(data_game);
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
		move_up(data_game);
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
		move_down(data_game);
}
