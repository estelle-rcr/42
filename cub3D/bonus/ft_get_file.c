/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:41:58 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:14:31 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**ft_get_file(int fd, int lvl)
{
	char	**tab;
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret > 0)
		tab = ft_get_file(fd, lvl + 1);
	else
	{
		if (!(tab = malloc((lvl + 2) * sizeof(char *))))
			return (NULL);
		tab[lvl] = line;
		tab[lvl + 1] = NULL;
		return (tab);
	}
	if (ret == -1)
		return (NULL);
	tab[lvl] = line;
	return (tab);
}
