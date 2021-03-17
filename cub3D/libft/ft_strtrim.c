/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:06:46 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/16 12:23:06 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (end)
	{
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
	}
	if (start > end)
		end = start;
	if (!(tab = malloc((end - start + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(tab, s1 + start, end - start);
	tab[end - start] = '\0';
	return (tab);
}
