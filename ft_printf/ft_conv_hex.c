/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:04:25 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 18:46:41 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int hex, t_flaglist *tmp)
{
	int count;
	int size;
	char *ar;

	count = 0;
	ar = ft_itoa_base((unsigned long long) hex, (tmp->type == 'x') ? HEX_L : 
			HEX_C);
	size = ((unsigned) tmp->size > ft_strlen(ar)) ? tmp->size : ft_strlen(ar);
	if (tmp->width > size)
	{		
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_hex(tmp, ar);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count = fill_hex(tmp, ar);
	free(ar);
	return (count);
}

int	fill_hex(t_flaglist *tmp, char *ar)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(ar);
	if (!ar && tmp->size < 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	if (tmp->precision && tmp->size > len)
		count += fill_space((tmp->size - len), '0');
	else if (!tmp->precision && tmp->left_justified == 0 &&
		tmp->zero_padded == 1)
		count += fill_space((tmp->width - len), '0');
	ft_putstr_fd(ar, 1);
	count += len;
	return (count);
}
