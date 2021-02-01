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
	int		size;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tab = malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		tab[i++] = *s1++;
	while (*s2)
		tab[i++] = *s2++;
	tab[i] = '\0';
	return (tab);
}
