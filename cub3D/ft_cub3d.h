/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/16 23:10:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define VALID_UNICODES "RSFC"
# define VALID_BICODES "NOSOWEEA"
# define MAP_CHARSET "012NSEW"
# define NB_SETTINGS 8

typedef struct		s_axis
{
	float	x;
	float	y;
}					t_axis;

/* typedef struct		s_type
{
	float	player_x;
	float	player_y;
	... resolution;
}					t_type;
*/

typedef struct		s_settings
{
	int		fd;
	t_axis	res;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*s_texture;
	int		f_color;
	int		c_color;
	char 	**map;
}					t_settings;

// ERRORS:

typedef enum	e_errors
{
// main
	ERR_NUMBER_ARGS,

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
}				t_errors;

// main
int	main(int ac, char **av);

// open_file
t_settings	init_set(void);
int	check_extension(char *file, char *type);
int	open_file(char *file);
int		is_whitespace(char *str);
int	read_file(char *file);

//cub3d utils
char	**free_tab(char **tab, int i);
int		count_elements(char **params);
int	atoi_res(const char *str);
int	check_atoi_colors(char *str);

// parser
int	check_params(char **params, t_settings *set);
int		all_params(t_settings *set);
int	parse_file(char *line, t_settings *set);

// parser_RTC
int	check_resolution(char **params, t_settings *set);
int	check_textures(char **params, t_settings *set);
int	check_colors(char **params, t_settings *set);

// split_sep
char	**ft_split_whitespaces(char *str);

// handle_errors
int	print_err_msg(int error);

// minilib_utils_color
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
//int		add_shade(double distance, int trgb);
//int		get_opposite(int trgb);

#endif
