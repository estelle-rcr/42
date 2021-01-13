/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:09:40 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/11 18:26:38 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_flaglist *tmp, const char *format, int *i, va_list args)
{
	while (format[*i])
	{
		*i = (*i) + 1;
		if (is_type(format[*i]) || format[*i] == '%')
		{
			tmp->type = format[*i];
			break;
		}
		else if (format[*i] == '-')
			tmp->left_justified = 1;
		else if (format[*i] == '0' && tmp->width == 0 && tmp->precision == 0)
		{
				tmp->zero_padded = 1;
		}
		else if (format[*i] == '.')
			tmp->precision = 1;
		else if (format[*i] == '*')
		{
			if (tmp->precision == 0)
				tmp->width = va_arg(args, int);
			else
			{
				tmp->size = va_arg(args, int);
			}
		}
		else if (ft_isdigit(format[*i]))
		{
			if (tmp->precision == 0)
				tmp->width = (tmp->width * 10) + (format[*i] - '0');
			else
				tmp->size = (tmp->size * 10) + (format[*i] - '0');
		}
	}
}

int	is_flag(char c)
{
	if (c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
