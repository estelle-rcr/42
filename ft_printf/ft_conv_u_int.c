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

int			print_u_int(unsigned int nb, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
	size = ((unsigned) tmp->size > (unsigned) ft_len_un(nb, 10)) ? tmp->size :
		ft_len_un(nb, 10);
	if (tmp->width > ft_len_un(nb, 10))
	{
		if (!tmp->precision || (tmp->precision && tmp->width > tmp->size))
		{
			if (tmp->left_justified == 1)
			{
				count += fill_u_int(tmp, nb);
				count += fill_space((tmp->width - size), ' ');
			}
			else if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			{
				count += fill_space((tmp->width - size), ' ');
				count += fill_u_int(tmp, nb);
			}
		}
		else
			count = fill_u_int(tmp, nb);
	}
	else
		count = fill_u_int(tmp, nb);
	return (count);
}

int			fill_u_int(t_flaglist *tmp, unsigned int nb)
{
	int count;
	int len;

	count = 0;
	len = ft_len_un(nb, 10);
	if (nb >= 0)
	{
		if (tmp->precision && tmp->size > len)
			count += fill_space((tmp->size - len), '0');
		else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
			count += fill_space((tmp->width - len), '0');
	}
	ft_putnbr_base(nb, DEC);
	count += len;
	return (count);
}

int			ft_len_un(unsigned int n, int len_base_to)
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

void	ft_putnbr_base(unsigned int n, char *base_to)
{
	unsigned long long nb;
	int len;

	nb = n;
	len = ft_strlen(base_to);
	if (nb >= 10)
	{
		ft_putnbr(nb / len);
		ft_putchar(nb % len + '0');
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	return ;
}
