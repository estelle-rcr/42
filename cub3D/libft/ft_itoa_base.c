/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:50:31 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 15:25:34 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(unsigned long long n, int len_base_to)
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

char		*ft_itoa_base(unsigned long long nb, char *base_to)
{
	int		count;
	int		sign;
	int		base_len;
	char	*tab;

	sign = 0;
	base_len = ft_strlen(base_to);
	count = ft_len(nb, base_len);
	if (!(tab = malloc((count + 1) * sizeof(char))))
		return (NULL);
	tab[count--] = '\0';
	if (nb < 0)
	{
		sign = 1;
		tab[0] = '-';
		nb *= -1;
	}
	while (count >= sign)
	{
		tab[count] = base_to[nb % base_len];
		nb /= base_len;
		count--;
	}
	return (tab);
}
