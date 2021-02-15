/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/10 23:04:41 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

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
	char	*f_texture;
	char	*c_texture;
}					t_settings;

// ERRORS:

typedef enum	e_errors
{
// main
	ERR_NUMBER_ARGS,

// open_file
	ERR_EXTENSION,
	ERR_OPENING_FILE,

// ft parse file
	ERR_MALLOC,
	ERR_MISSING_PARAMS,

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

}				t_errors;

#endif