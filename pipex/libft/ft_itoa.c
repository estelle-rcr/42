/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:07:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 15:06:02 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*tab;
	long	nb;

	sign = 0;
	count = ft_len(n);
	tab = malloc((count + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[count--] = '\0';
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		tab[0] = '-';
		nb *= -1;
	}
	while (count >= sign)
	{
		tab[count] = (nb % 10) + '0';
		nb /= 10;
		count--;
	}
	return (tab);
}
