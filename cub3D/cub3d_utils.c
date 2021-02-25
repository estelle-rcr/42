/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:55:32 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 23:19:55 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}

int	atoi_res(const char *str)
{
	long	nb;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
			return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (*str || nb > 2147483647 || nb < -2147483648)
		return (0);
	return ((int)nb);
}

/*
** If there is a '+' or a '-' (or any unexpected char), the following function exits with an error code
*/

int	check_atoi_colors(char *str)
{
	int	nb;
	int j;

	nb = 0;
	j = 0;
	while ((*str >= '0' && *str <= '9') || *str == ',')
	{
		if (nb > 255)
			break ;
		else if (*str == ',')
		{
			j++;
			nb = 0;
		}
		else
			nb= (nb * 10) + (*str - '0');
		str++;
	}
	if (*str || (j != 2) || nb > 255)
		return (0);
	return (1);
}
