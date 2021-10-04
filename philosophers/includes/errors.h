/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:35:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 12:55:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_errors
{
	ERR_NB_ARGS,
	ERR_ARGS_LIMIT,
	ERR_WRG_ARGS,
	ERR_MALLOC_STRUCT,
	ERR_MALLOC_DATA,
	ERR_MUTEX_FAIL,
	ERR_THREAD_FAIL,
}				t_errors;

#endif
