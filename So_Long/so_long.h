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

typedef struct textures_struct {
    mlx_texture_t   *floor;
    mlx_texture_t   *wall;
    mlx_texture_t   *player;
    mlx_texture_t   *en_mantis;
    mlx_texture_t   *en_oso;
    mlx_texture_t   *collect;
    mlx_texture_t   *exit;
    mlx_image_t     *floor_img;
    mlx_image_t     *wall_img;
    mlx_image_t     *player_img;
    mlx_image_t     *en_mantis_img;
    mlx_image_t     *en_oso_img;
    mlx_image_t     *collect_img;
    mlx_image_t     *exit_img;
}                   textures_data;

typedef struct mappoint_type {
    int x;
    int y;
}       map_point;

typedef struct data_type {
    int             fd;
    int             mapwidth;
    int             mapheight;
    int             error_code;
    int             aux_i;

    char            **map;
    int             moves;
    int             collects_total;
    int             collected;
    bool            exit;
    map_point       beg;
    map_point       end;

    mlx_t           *mlx;
    textures_data   textures;
}                   data_struct;

int     ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
char    *ft_strchr(char *s, int c);
size_t  ft_strlen(char *s);
size_t  ft_strlcpy(char *dst, char *src, size_t dstsize);

void    *ft_memset(void *b, int c, size_t length);

char    *clean_line(char *line);
void    read_map(data_struct *data_game, char **argv);

void    exit_error(data_struct *data_game, int error_code, char *line);
void    walls_error(data_struct *data_game);
void    element_error(data_struct *data_game);
void    path_error(data_struct *data_game);

void    ft_free_mat(char ***mat, int i);
void    free_exit(data_struct *data_game, char **temp, char **temp_aux, 
    char *line);

void    kind_realloc(data_struct *data_game, char ***matrix, char ***matrix2,
    char *line);
void    aux_copy(data_struct *data_game, char ***temp_aux, char ***temp, 
    char *line);
void    add_line(data_struct *data_game, char **line);
void    finish_parseo(data_struct *data_game, char **temp);

int     locate_element(char **map, int height, map_point *p, char c);
char    **copy_map(char **ori_map, int n_lines, int l_line);
void    flood_fill(char **map, map_point p, int mapwidth, int mapheight);
int     fill_checker(char **map, int mapheight);

void    start_game(data_struct *data_game);

void    key_controller(struct mlx_key_data key_data, void *param);
void	void_cell(int i, int j, data_struct *data_game);
void	collect_cell(int i, int j, data_struct *data_game);
void	exit_cell(int i, int j, data_struct *data_game);

void    enemies_turn(data_struct *data_game);
void    display_moves(data_struct *data_game);
char	*ft_itoa(int n);
void    flip_sprite(data_struct *data_game, mlx_texture_t **texture, 
    mlx_image_t **sprite, char *rute);

#endif