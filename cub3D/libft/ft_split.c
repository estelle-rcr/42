/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:07:02 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 23:21:24 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_word_len(char const *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str != c)
			i++;
		else if (*str == c)
			return (i);
		str++;
	}
	return (i);
}

static int		ft_word_count(char const *str, char c)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str == c)
			flag = 0;
		else if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static	char	**free_tab(char **tab, int i)
{
	while (i--)
		free((void *)tab[i]);
	free((void *)tab);
	return (NULL);
}

static	char	**ft_create_tabs(char const *str, char c, char **tab)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (j == 0)
			{
				i++;
				if (!(tab[i] = malloc(sizeof(char) *
					((ft_word_len(str, c) + 1)))))
					return (free_tab(tab, i));
			}
			tab[i][j] = *str;
			tab[i][++j] = '\0';
		}
		else if (*str == c && j > 0)
			j = 0;
		str++;
	}
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	tab = ft_create_tabs(s, c, tab);
	return (tab);
}
