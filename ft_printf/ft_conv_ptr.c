/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:05:04 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/12 11:49:35 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr, t_flaglist *tmp)
{
	int count;
	int size;
	char *ar;

	count = 0;
	ar = ft_strjoin("0x", ft_itoa_base((unsigned long long) ptr, HEX_L));
	size = ft_strlen(ar);
	if (tmp->width > size)
	{
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_ptr(tmp, ar);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count = fill_ptr(tmp, ar);
	free(ar);
	return (count);
}

int	fill_ptr(t_flaglist *tmp, char *ptr)
{
	int count;

	count = 0;
	if (!ptr && tmp->size < 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	ft_putstr_fd(ptr, 1);
	count += ft_strlen(ptr);
	return (count);
}
/*
int			ft_len_unl(unsigned long n, int len_base_to)
{
	int		count;

	count = 0;
	while (n)
	{
		count++;
		n /= len_base_to;
	}
	return (count);
}

void	ft_putnbl_base(unsigned long n, char *base_to)
{
	unsigned long nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / ft_strlen(base_to), 1);
		ft_putchar_fd(base_to[nb % ft_strlen(base_to)] + '0', 1);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd((base_to[nb + '0']), 1);
	return ;
}*/
