/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:08:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/12 18:18:49 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u_int(unsigned int nb, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	correct_val_int(tmp, nb);
	size = (tmp->size > ft_len_un(nb, 10)) ? tmp->size : ft_len_un(nb, 10);
	if (tmp->width > ft_len_un(nb, 10))
	{
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_u_int(tmp, nb);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count = fill_u_int(tmp, nb);
	return (count);
}

int		fill_u_int(t_flaglist *tmp, unsigned int nb)
{
	int count;
	int len;

	count = 0;
	len = ft_len_un(nb, 10);
	if (tmp->precision)
		count += fill_space((tmp->size - len), '0');
	else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
		count += fill_space((tmp->width - len), '0');
	if (!nb && !tmp->size && tmp->precision)
		return (handle_null_int(tmp, count));
	ft_putnbr_base(nb, DEC);
	count += len;
	return (count);
}

int		ft_len_un(unsigned int n, int len_base_to)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= len_base_to;
	}
	return (count);
}

void	ft_putnbr_base(unsigned int n, char *base_to)
{
	unsigned long long	nb;
	int					length;

	nb = n;
	length = ft_strlen(base_to);
	if (nb >= 10)
	{
		ft_putnbr(nb / length);
		ft_putchar(nb % length + '0');
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	return ;
}
