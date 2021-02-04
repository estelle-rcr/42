/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:06:24 by erecuero          #+#    #+#             */
/*   Updated: 2020/11/23 12:06:26 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(tab = malloc((size1 + size2 + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(tab, s1, size1);
	ft_memmove(tab + size1, s2, size2);
	tab[size1 + size2] = '\0';
	return (tab);
}
