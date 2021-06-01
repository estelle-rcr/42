/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:21:26 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/16 12:23:11 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*src;

	i = 0;
	src = (char *)haystack;
	if (!*needle)
		return (src);
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return (&src[i]);
		}
		i++;
	}
	return (0);
}
