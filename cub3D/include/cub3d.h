/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/09 22:51:55 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "minilibx-linux/mlx.h"

# define MAP_CHARSET "012NSEW"
# define PLAY_CHARSET "02NSEW"
# define DIR_CHARSET "NSEW"
# define NB_SETTINGS 8

typedef struct		s_axis
{
	float	x;
	float	y;
}					t_axis;

typedef struct		s_settings
{
	int		fd;
	t_axis	res;
	t_axis	start_pos;
	char	player_dir;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*s_texture;
	int		f_color;
	int		c_color;
	char 	**map;
	int		map_width;
	int		map_height;
}					t_settings;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img_data;

typedef struct	s_text_data
{
	void	*img;
	char	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}				t_text_data;

typedef struct	s_game
{
	t_settings	set;
	void	*mlx;
	void	*win;
	t_img_data	img;
	t_text_data	north_txt;
	t_text_data	south_txt;
	t_text_data	west_txt;
	t_text_data	east_txt;
	t_text_data	sprites_txt;
	//t_player	player;
	//t_ray		*rays;
	float	dst_projection;
}				t_game;

/*typedef struct	s_player
{

}				t_player;

typedef struct	s_ray
{

}				t_ray;
*/

// ERRORS:

typedef enum	e_errors
{
// main
	ERR_ARGS,

// open_file
	ERR_EXTENSION,
	ERR_OPENING_DIR,
	ERR_OPENING_FILE,

// ft_parse_file
	ERR_MALLOC,
	ERR_MISSING_PARAMS,
	ERR_GNL,

// ft check params
	ERR_CODE_NOT_VALID,

// ft check resolution
	ERR_NEGATIVE_RES,
	ERR_RES_ALREADY_ADDED,
	ERR_RES_FORMAT,
	ERR_RES_INPUTS,

//ft check textures
	ERR_TEX_INPUTS,
	ERR_TEX_FORMAT,
	ERR_TEX_ALREADY_ADDED,

// ft check colors
	ERR_COLOR_INPUTS,
	ERR_COLOR_FORMAT,
	ERR_COLOR_ALREADY_ADDED,

// map parser
	ERR_NOT_MAP_LINE,
	ERR_INVALID_MAP,
	ERR_PLAYER_COUNT,

// mlx error
	ERROR_INIT_MLX,
	ERROR_INIT_MLX_WIN,
	ERROR_IMG_MLX,

}				t_errors;

// main
int			main(int ac, char **av);

// open_file
void		init_set(t_settings);
int			check_extension(char *file, char *type);
int			open_file(char *file);
int			is_whitespace(char *str);
int			read_file(char *file, t_settings set);

//cub3d parser utils
char		**free_tab(char **tab);
int			atoi_res(const char *str);
int			check_atoi_colors(char *str);
void		free_map(char **map);

// parser
int			check_params(char **params, t_settings *set);
int			all_params(t_settings *set);
int			parse_file(char *line, t_settings *set);

// parser_RTC
int			check_resolution(char **params, t_settings *set);
int			check_textures(char **params, t_settings *set);
int			check_colors(char **params, t_settings *set);

// split_sep
char		**ft_split_whitespaces(char *str);

// handle_errors
int			print_err_msg(int error);
int			error_files(int error);
int			error_rtc(int error);
int			error_map(int error);
int			error_mlx(int error);

// minilib_utils_color
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
//int		add_shade(double distance, int trgb);
//int		get_opposite(int trgb);

// parser_map
int			is_map(char *s);
char		*replace_tabs(char *line);
char		*ft_strdup_fill(const char *s1, int len);
int 		copy_map(char *line, t_settings *set);
int			get_map(char *line, t_settings *set);

// check_map
int 		is_valid_map(char **map);
int 		valid_cells(char case1, char case2);
int 		get_player_position(t_settings *set);
int			comp_null_cells(char **map, int x, int y);
int			check_map(t_settings *set);

// floodfill
int			flood_fill(char **copy_map, float pos_x, float pos_y);

// init_mlx
int			run_mlx(t_game *game, int save);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int			my_mlx_new_img(void *mlx, t_img_data *img, int x, int y);
int			create_mlx_win(t_game *game);

#endif
