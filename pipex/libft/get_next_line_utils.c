/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:22:44 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 13:56:35 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strfind(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (0);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (s < d)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (len-- > 0)
			*d++ = *s++;
	return (dst);
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
	tab = malloc((size1 + size2 + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_memmove(tab, s1, size1);
	ft_memmove(tab + size1, s2, size2);
	tab[size1 + size2] = '\0';
	free(s1);
	return (tab);
}

void	helper_gnl(char *buf, char **line, char *str)
{
	free(buf);
	*line = new_line(str);
	str = trunc_str(str);
}
