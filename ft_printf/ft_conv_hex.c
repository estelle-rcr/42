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
	int		count;
	int		size;
	char	*ar;

	count = 0;
	ar = ft_itoa_base((unsigned long long)hex, (tmp->type == 'x') ? HEX_L :
			HEX_C);
	size = ((int)tmp->size > (int)ft_strlen(ar)) ? tmp->size : ft_strlen(ar);
	correct_val_int(tmp, hex);
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
	if (tmp->precision)
		count += fill_space((tmp->size - len), '0');
	else if (!tmp->precision && tmp->left_justified == 0 &&
		tmp->zero_padded == 1)
		count += fill_space((tmp->width - len), '0');
	if (ar[0] == '0' && !tmp->size && tmp->precision)
		return (handle_null_int(tmp, count));
	ft_putstr_fd(ar, 1);
	count += len;
	return (count);
}
