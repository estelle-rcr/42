/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:05:04 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 18:47:17 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr, t_flaglist *tmp)
{
	int		count;
	int		size;
	char	*pt;
	char	*ar;

	count = 0;
	pt = ft_itoa_base((unsigned long long)ptr, HEX_L);
	ar = (!ptr && tmp->precision) ? ft_joinstr("0x", 0) :
		ft_joinstr("0x", pt);
	if (pt)
		free(pt);
	size = ft_strlen(ar);
	if (tmp->width > size)
	{
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_ptr(ar);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count = fill_ptr(ar);
	free(ar);
	return (count);
}

int	fill_ptr(char *ptr)
{
	int count;

	count = 0;
	ft_putstr_fd(ptr, 1);
	count += ft_strlen(ptr);
	return (count);
}
