/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:06:00 by erecuero          #+#    #+#             */
/*   Updated: 2020/11/23 12:06:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(sub = malloc(sizeof(char))))
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	while (start--)
		s++;
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i++] = *s++;
	}
	sub[i] = '\0';
	return (sub);
}
