/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:05:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/12 15:39:52 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, t_flaglist *tmp)
{
	int count;
	int s_len;

	count = 0;
	if (!s)  
		s_len = 6;
	else
		s_len = ft_strlen(s);
	correct_val_str(tmp, s_len);
	if (tmp->width)
	{
		if (tmp->left_justified == 1 && tmp->width > 0)
		{
			count += fill_str(tmp, s);
			count += fill_space((tmp->width - tmp->size), ' ');
		}
		else if (tmp->left_justified == 0 && tmp->width > 0)
		{
			count += fill_space((tmp->width - tmp->size), ' ');
			count += fill_str(tmp, s);
		}
	}
	else
	{
		count = fill_str(tmp, s);
	}
	return (count);		//else n'imprime rien, implicite
}

void	correct_val_str(t_flaglist *tmp, int s_len)
{
	if (tmp->width && tmp->width < 0)
		tmp->width = -tmp->width;
	if (!(tmp->size > s_len))
		tmp->size = s_len;
/*	if (tmp->size && tmp->size > s_len)
		tmp->size = s_len;
	else if (tmp->size && tmp->size < 0)
		tmp->size = s_len;
	if (!tmp->precision)
		tmp->size = s_len;*/
}

int	fill_str(t_flaglist *tmp, char *s)
{
	int i;
	int count;

	i = 0;
	while (s && tmp->size > i)
		ft_putchar(s[i++]);
	if (!s)
	{
		ft_putstr("(null)");
		count = 6;
	}
	else
		count = tmp->size;
	return (count);
}
