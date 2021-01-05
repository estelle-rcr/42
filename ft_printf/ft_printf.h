/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:32:07 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/04 21:32:12 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	char	type;
	int	left_justify;
	int	zero_pads;
	int	width;
	int	precision;
	int	value;
}			t_flags;

int	ft_printf(const char *format, ...);
int	convert_args(const char *format, va_list ap, int *i, int *size);
