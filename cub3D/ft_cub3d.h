/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

/*
typedef struct		s_type
{
	float	player_x;
	float	player_y;
	... resolution;
}					t_type;
*/

typedef struct		s_settings
{
	int 	fd;
	int		res_x;
	int		res_y;
	char	*NO_texture;
	char 	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*s_texture;
	char	*f_texture;
	char	*c_texture;
}					t_settings;


#endif
