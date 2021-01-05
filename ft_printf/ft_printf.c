/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:10:21 by erecuero          #+#    #+#             */
/*   Updated: 2020/12/15 16:10:23 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	tmp;	
	int	i;
	int	count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i++] == '%')
		{
			flags = new_flaglist();
			get_flags(&tmp, format, &i, args);
			if (tmp.type != 0)
				count += print_args(tmp, args);
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

void	get_flags(t_flags *tmp, const char *format, int *i, va_list args)
{
	while (format[*i])
	{
		


