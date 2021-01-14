/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:04:33 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 19:00:52 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int nb, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	if ((unsigned) tmp->size > (unsigned) ft_len_nb(nb, 10)) 
		size = tmp->size;
	else
		size = ft_len_nb(nb, 10);
/*	if (nb < 0)
	{
		count++;
	}*/
	if (tmp->width > ft_len_nb(nb, 10))
	{
			if (tmp->left_justified == 0 && tmp->zero_padded == 0)
				count += fill_space((tmp->width - size), ' ');
			count += fill_int(tmp, nb);
			if (tmp->left_justified == 1)
				count += fill_space((tmp->width - size), ' ');
	}
	else
		count += fill_int(tmp, nb);	
	return (count);	
}

int	fill_int(t_flaglist *tmp, int nb)
{
	int count;
	int len;
	int sign;
	long n;
	
	count = 0;
	sign = 0;
	len = ft_len_nb(nb, 10);
	n = nb;
	if (nb < 0)
	{
		n = -n;
		ft_putchar('-');
		sign++;
	}
//	if (nb > 0)
//	{
		if (tmp->precision && tmp->size > len)
			count += fill_space((tmp->size - len + sign), '0');
		else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
			count += fill_space((tmp->width - len), '0');
		ft_putnbr(n);
		count += len;
//	}
	return (count);
}

int	ft_len_nb(int n, int len_base_to)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return ((count = 11));	
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n /= len_base_to;
		count++;
	}
	return (count);
}
