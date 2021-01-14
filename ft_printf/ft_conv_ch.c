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

	count = 0;
	if (tmp->width)
	{
		if (tmp->left_justified == 0 && tmp->width > 0)
			count += fill_space((tmp->width - 1), ' ');
		count += fill_ch(c);
		if (tmp->left_justified == 1 && tmp->width > 0)
			count += fill_space((tmp->width - 1), ' ');
	}
	else
			count += fill_ch(c);
	return (count);
}

int	fill_ch(char c)
{
	int count;

	ft_putchar(c);
	count = 1;
	return (count);
}
