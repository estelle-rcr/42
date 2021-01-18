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

int		print_int(int nb, t_flaglist *tmp)
{
	int count;
	int size;
	int sign;

	count = 0;
	sign = (nb < 0) ? 1 : 0;
	correct_val_int(tmp, nb);
	if ((unsigned)tmp->size >= (unsigned)ft_len_nb(nb, 10))
		size = tmp->size + sign;
	else
		size = ft_len_nb(nb, 10);
	if (tmp->width > ft_len_nb(nb, 10))
	{
		if (tmp->left_justified == 0 && tmp->zero_padded == 0)
			count += fill_space((tmp->width - size), ' ');
		count += fill_int(tmp, nb, sign);
		if (tmp->left_justified == 1)
			count += fill_space((tmp->width - size), ' ');
	}
	else
		count += fill_int(tmp, nb, sign);
	return (count);
}

int		fill_int(t_flaglist *tmp, int nb, int sign)
{
	unsigned int	n;
	int				count;
	int				len;

	count = 0;
	len = ft_len_nb(nb, 10);
	n = (unsigned int)nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (tmp->precision)
		count += fill_space((tmp->size - (len - sign)), '0');
	else if (!tmp->precision && tmp->left_justified == 0 &&
				tmp->zero_padded == 1)
		count += fill_space((tmp->width - len), '0');
	if (!n && !tmp->size && tmp->precision)
		return (handle_null_int(tmp, count));
	ft_putnbr_uns(nb, DEC);
	count += len;
	return (count);
}

int		handle_null_int(t_flaglist *tmp, int count)
{
	if (!tmp->width)
		return (count);
	else
	{
		ft_putchar(' ');
		return ((count + 1));
	}
}

int		ft_len_nb(int n, int len_base_to)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= len_base_to;
		count++;
	}
	return (count);
}

void	ft_putnbr_uns(unsigned int nb, char *base_to)
{
	int	length;
	int	n;

	if (nb == 2147483648)
		return (ft_putnbr_base(nb, DEC));
	n = (int)nb;
	length = ft_strlen(base_to);
	if (n < 0)
		ft_putnbr(-n);
	else if (n >= 10)
	{
		ft_putnbr(n / length);
		ft_putchar(n % length + '0');
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return ;
}
