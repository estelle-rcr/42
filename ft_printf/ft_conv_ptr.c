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

int			print_ptr(unsigned long nb, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	size = ((unsigned) tmp->size > (unsigned) ft_len_unl(nb, 10)) ? tmp->size :
		ft_len_unl(nb, 10);
	if (tmp->width > ft_len_unl(nb, 10))
	{
		if (!tmp->precision || (tmp->precision && tmp->width > tmp->size))
		{
			if (tmp->left_justified == 1)
			{
				count += fill_ptr(tmp, nb);
				count += fill_space((tmp->width - size), ' ');
			}
			else if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			{
				count += fill_space((tmp->width - size), ' ');
				count += fill_ptr(tmp, nb);
			}
		}
		else
			count = fill_ptr(tmp, nb);
	}
	else
		count = fill_ptr(tmp, nb);
	return (count);
}

int			fill_ptr(t_flaglist *tmp, unsigned long nb)
{
	int count;
	int len;
	count = 0;
	len = ft_len_unl(nb, 10);
	if (nb >= 0)
	{
		if (tmp->precision && tmp->size > len)
			count += fill_space((tmp->size - len), '0');
		else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
			count += fill_space((tmp->width - len), '0');
	}
	ft_putstr("0x");
	if (!nb && tmp->size < 0)
	{
		ft_putstr("0");
		count++;
	}
	ft_putnbl_base(nb, HEX_L_BASE);
	count += (len + 2);
	return (count);
}

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
	unsigned long long nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / ft_strlen(base_to));
		ft_putchar(nb % ft_strlen(base_to) + '0');
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	return ;
}
/* void	correct_val_ptr(t_flaglist *tmp)
{
	if (tmp->width && tmp->width < 0)
		tmp->width = -tmp->width;
}*/
