/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/10 20:36:13 by erecuero         ###   ########.fr       */
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
	int		res_x;
	int		res_y;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*s_texture;
	char	*f_texture;
	char	*c_texture;
}					t_settings;

typedef	enum	e_set
{
	R,
	NO,

}






// ERRORS:

typedef enum e_errors
{

}



#endif
