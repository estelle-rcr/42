/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:04:33 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/12 18:17:04 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int nb, t_flaglist *tmp)
{
	int count;
	int size;

	count = 0;
//	correct_val_int(tmp, nb);
	if ((unsigned) tmp->size > (unsigned) ft_len_nb(nb, 10)) 
		size = tmp->size;
	else
		size = ft_len_nb(nb, 10);
	if (nb < 0)
	{
		count++;
		size++;
	}
	if (tmp->width > ft_len_nb(nb, 10))
	{
		if (!tmp->precision || (tmp->precision && tmp->width > tmp->size))
		{
			if (tmp->left_justified == 1)
			{
				count += fill_int(tmp, nb);
				count += fill_space((tmp->width - size), ' ');
			}
			else if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			{	
				count += fill_space((tmp->width - size), ' ');
				count += fill_int(tmp, nb);
			}	
		}
		else
			count = fill_int(tmp, nb);	
	}
	else
		count = fill_int(tmp, nb);	
	return (count);	
}


/*void	correct_val_int(t_flaglist *tmp, int nb)
{
	if (tmp->width && tmp->width < 0)
		tmp->width = ft_len_nb(nb, 10);
}*/

int	fill_int(t_flaglist *tmp, int nb)
{
	int count;
	int len;
	
	count = 0;
	len = ft_len_nb(nb, 10);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		len--;
	}
	if (nb > 0)
	{
		if (tmp->precision && tmp->size > len)
			count += fill_space((tmp->size - len), '0');
		else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
			count += fill_space((tmp->width - len), '0');
		ft_putnbr(nb);
		count += ft_len_nb(nb, 10);
	}
	return (count);
}

int	ft_len_nb(int n, int len_base_to)
{
	int		count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= len_base_to;
	}
	return (count);
}
