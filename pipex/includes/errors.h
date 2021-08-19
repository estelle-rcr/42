/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:35:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/19 17:18:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_errors
{
	ERR_ARGS,
	ERR_INFILE,
	ERR_OUTFILE,
	ERR_PATH,
	ERR_PIPE,
	ERR_FORK,
	ERR_DUP,
	ERR_CMD,
	ERR_JOIN,
	ERR_EXECVE,
}				t_errors;

#endif
