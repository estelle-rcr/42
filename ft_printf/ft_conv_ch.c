/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:03:40 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 18:42:15 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	size = 1;
	if (tmp->type == '%' && tmp->size > 1 && tmp->zero_padded)
		size = tmp->size;
	if (tmp->width)
	{
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_ch(c, tmp);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count += fill_ch(c, tmp);
	return (count);
}

int	fill_ch(char c, t_flaglist *tmp)
{
	int count;

	count = 0;
	if (tmp->type == '%' && tmp->left_justified == 0 &&
		tmp->zero_padded == 1)
		count += fill_space((tmp->width - 1), '0');
	ft_putchar(c);
	count += 1;
	return (count);
}
