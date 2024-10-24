/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:28 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/09/05 15:49:28 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>

typedef struct textures_struct
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*en_mantis;
	mlx_texture_t	*en_oso;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*en_mantis_img;
	mlx_image_t		*en_oso_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*exit_img;
}					t_textures_data;

typedef struct mappoint_type
{
	int	x;
	int	y;
}	t_map_point;

typedef struct data_type
{
	int				fd;
	int				mapwidth;
	int				mapheight;
	int				error_code;
	int				aux_i;

	char			**map;
	int				moves;
	int				collects_total;
	int				collected;
	bool			exit;
	t_map_point		beg;
	t_map_point		end;

	mlx_t			*mlx;
	t_textures_data	textures;
}					t_data_struct;

int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

void	*ft_memset(void *b, int c, size_t length);

char	*clean_line(char *line);
void	read_map(t_data_struct *data_game, char **argv);

void	exit_error(t_data_struct *data_game, int error_code, char *line);
void	walls_error(t_data_struct *data_game);
void	element_error(t_data_struct *data_game);
void	path_error(t_data_struct *data_game);

void	ft_free_mat(char ***mat, int i);
void	free_exit(t_data_struct *data_game, char **temp, char **temp_aux,
			char *line);

void	kind_realloc(t_data_struct *data_game, char ***matrix, char ***matrix2,
			char *line);
void	aux_copy(t_data_struct *data_game, char ***temp_aux, char ***temp,
			char *line);
void	add_line(t_data_struct *data_game, char **line);
void	finish_parseo(t_data_struct *data_game, char **temp);

int		locate_element(char **map, int height, t_map_point *p, char c);
char	**copy_map(char **ori_map, int n_lines, int l_line);
void	flood_fill(char **map, t_map_point p, int mapwidth, int mapheight);
int		fill_checker(char **map, int mapheight);

void	start_game(t_data_struct *data_game);

void	key_controller(struct mlx_key_data key_data, void *param);
void	void_cell(int i, int j, t_data_struct *data_game);
void	collect_cell(int i, int j, t_data_struct *data_game);
void	exit_cell(int i, int j, t_data_struct *data_game);

void	enemies_turn(t_data_struct *data_game);
void	display_moves(t_data_struct *data_game);
char	*ft_itoa(int n);
void	flip_sprite(t_data_struct *data_game, mlx_texture_t **texture,
			mlx_image_t **sprite, char *rute);

#endif