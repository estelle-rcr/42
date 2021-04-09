/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:19:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/25 13:20:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

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
    ERROR_TXT_LOAD_IMG,

}				t_errors;

#endif