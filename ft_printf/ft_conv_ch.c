/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:03:40 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/11 18:19:47 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_flaglist *tmp)
{
	int count;

	count = 0;
	correct_val_ch(tmp);
	if (tmp->width)
	{
		if (tmp->left_justified == 1 && tmp->width > 0)
		{
			count += fill_ch(c);
			count += fill_space((tmp->width - 1), ' ');
		}
		else if (tmp->left_justified == 0 && tmp->width > 0)
		{
			count += fill_space((tmp->width - 1), ' ');
			count += fill_ch(c);
		}
	}
	else
			count += fill_ch(c);
	return (count);
}

void	correct_val_ch(t_flaglist *tmp)
{
	if (tmp->width && tmp->width < 0)
		tmp->width = -tmp->width;
}

int	fill_ch(char c)
{
	int count;

	ft_putchar(c);
	count = 1;
	return (count);
}
