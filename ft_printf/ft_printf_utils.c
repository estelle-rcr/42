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

char	*ft_joinstr(char *s1, char *s2)
{
	char	*tab;
	int		size1;
	int		size2;

	if (!s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(tab = malloc((size1 + size2 + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(tab, s1, size1);
	ft_memmove(tab + size1, s2, size2);
	tab[size1 + size2] = '\0';
	free(s1);
	free(s2);
	return (tab);
}
