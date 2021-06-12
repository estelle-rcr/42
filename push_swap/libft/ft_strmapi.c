/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:07:38 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 14:03:37 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (s)
	{
		tab = ft_strdup((char const *)s);
		if (!tab)
			return (NULL);
		i = 0;
		while (tab[i])
		{
			tab[i] = f((unsigned int)i, tab[i]);
			i++;
		}
		return (tab);
	}
	return (NULL);
}
