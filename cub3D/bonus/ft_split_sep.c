/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:52:27 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:14:33 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		ft_is_sep(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		return (1);
	return (0);
}

static int		ft_word_len(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_is_sep(str) == 0)
			i++;
		else if (ft_is_sep(str) == 1)
			return (i);
		str++;
	}
	return (i);
}

static int		ft_word_count(char *str)
{
	int flag;
	int count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (ft_is_sep(str))
			flag = 0;
		else if (!ft_is_sep(str) && flag == 0)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char		**ft_create_tabs(char *str, char **tab)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (*str)
	{
		if (ft_is_sep(str) == 0)
		{
			if (j == 0)
			{
				i++;
				if (!(tab[i] = malloc(sizeof(char) *
								((ft_word_len(str) + 1)))))
					return (free_tab(tab));
			}
			tab[i][j] = *str;
			tab[i][++j] = '\0';
		}
		else if (ft_is_sep(str) == 1 && j > 0)
			j = 0;
		str++;
	}
	return (tab);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		count;

	count = ft_word_count(str);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = 0;
	tab = ft_create_tabs(str, tab);
	return (tab);
}
