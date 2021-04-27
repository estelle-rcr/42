/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:19:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 23:41:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

typedef enum	e_errors
{
	ERR_ARGS,
	ERR_EXTENSION,
	ERR_OPENING_DIR,
	ERR_OPENING_FILE,
	ERR_MALLOC,
	ERR_MISSING_PARAMS,
	ERR_GNL,
	ERR_CODE_NOT_VALID,
	ERR_NEGATIVE_RES,
	ERR_RES_ALREADY_ADDED,
	ERR_RES_FORMAT,
	ERR_RES_INPUTS,
	ERR_TEX_INPUTS,
	ERR_TEX_FORMAT,
	ERR_TEX_ALREADY_ADDED,
	ERR_COLOR_INPUTS,
	ERR_COLOR_FORMAT,
	ERR_COLOR_ALREADY_ADDED,
	ERR_NOT_MAP_LINE,
	ERR_INVALID_MAP,
	ERR_PLAYER_COUNT,
	ERROR_INIT_MLX,
	ERROR_INIT_MLX_WIN,
	ERROR_IMG_MLX,
	ERROR_TXT_LOAD_IMG,
	ERR_MLX_DESTROY,
	ERROR_OPEN_BMP,
	ERROR_CLOSE_BMP,
	ERROR_CLOSE_FILE,
	ERROR_GNL,

}				t_errors;

#endif
