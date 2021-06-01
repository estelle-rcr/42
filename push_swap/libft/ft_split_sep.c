/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:52:59 by erecuero          #+#    #+#             */
/*   Updated: 2021/05/20 12:41:42 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_sep(char *str, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int		ft_word_len(char *str, char *charset)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_is_sep(str, charset) == 0)
			i++;
		else if (ft_is_sep(str, charset) == 1)
			return (i);
		str++;
	}
	return (i);
}

static int		ft_word_count(char *str, char *charset)
{
	int i;
	int flag;
	int count;

	i = 0;
	flag = 0;
	count = 0;
	while (*str)
	{
		if (ft_is_sep(str, charset))
			flag = 0;
		else if (!ft_is_sep(str, charset) && flag == 0)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char		**ft_create_tabs(char *str, char *charset, char **tab)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (*str)
	{
		if (ft_is_sep(str, charset) == 0)
		{
			if (j == 0)
			{
				i++;
				if (!(tab[i] = malloc(sizeof(char) *
								((ft_word_len(str, charset) + 1)))))
					return (ft_free_tab(tab));
			}
			tab[i][j] = *str;
			tab[i][++j] = '\0';
		}
		else if (ft_is_sep(str, charset) == 1 && j > 0)
			j = 0;
		str++;
	}
	return (tab);
}

char		**ft_split_sep(char *str, char *charset)
{
	char	**tab;
	int		count;

	count = ft_word_count(str, charset);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	tab = ft_create_tabs(str, charset, tab);
	return (tab);
}
