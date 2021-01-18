/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:05:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 18:43:16 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(char *s, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	s = handle_null(s);
	if (tmp->precision && ft_strlen(s) > (unsigned)tmp->size)
		size = tmp->size;
	else
		size = ft_strlen(s);
	if (tmp->width)
	{
		if (tmp->left_justified == 0 && tmp->width > 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_str(tmp, s);
		if (tmp->left_justified == 1 && tmp->width > 0)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count += fill_str(tmp, s);
	return (count);
}

int		fill_str(t_flaglist *tmp, char *s)
{
	int count;

	count = 0;
	if (!tmp->precision)
		tmp->size = ft_strlen(s);
	while (s && s[count] && tmp->size > count)
		ft_putchar(s[count++]);
	return (count);
}

char	*handle_null(char *s)
{
	if (!s)
	{
		s = "(null)";
	}
	return (s);
}
