/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:10:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/12 18:29:44 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flaglist	tmp;
	int			i;
	int 		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = new_flaglist();
			get_flags(&tmp, format, &i, args);
			if (tmp.type != 0) 					// May not be necessary
				count += print_arg(&tmp, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	print_arg(t_flaglist *tmp, va_list args)
{
	int	rtn;

	rtn = 0;
/*	if (tmp->type == 'c')
		rtn = print_char(va_arg(args, int), tmp);
	else if (tmp->type == 's')
		rtn = print_str(va_arg(args, char *), tmp);
*/	 if (tmp->type == 'p')
		rtn = print_ptr(va_arg(args, void *), tmp);
/*	else if (tmp->type == 'i' || tmp->type == 'd')
		rtn = print_int(va_arg(args, int), tmp);
	else if (tmp->type == 'u')
		rtn = print_u_int(va_arg(args, unsigned int), tmp);
*/	else if (tmp->type == 'x')
		rtn = print_hex(va_arg(args, unsigned int), tmp);
	else if (tmp->type == 'X')
		rtn = print_hex(va_arg(args, unsigned int), tmp);
/*	else if (tmp->type == '%')
		rtn = print_char('%', tmp);*/
	return (rtn);
}
