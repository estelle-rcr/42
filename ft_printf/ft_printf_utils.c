/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:10:32 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/11 17:51:21 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flaglist	new_flaglist(void)
{
	t_flaglist	tmp;

	tmp.type = 0;
	tmp.left_justified = 0;
	tmp.zero_padded = 0;
	tmp.width = 0;
	tmp.precision = 0;
	tmp.size = 0;
	return (tmp);
}

int	fill_space(int i, char c)
{
	int count;

	count = i;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
	return (count);
}
