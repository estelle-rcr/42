/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:55:32 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 00:31:58 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	**free_tab(char **tab, int i)
{
	while (i--)
		free((void *)tab[i]);
	free((void *)tab);
	return (0);
}

int		count_elements(char **params)
{
	int i;

	i = 0;
	while (params[i])
		i++;
	return (i);
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
	int	nb[3];
	int 	i;
	int 	j;

	i = 0;
	nb[i] = 0;
	j = 0;
	while ((*str >= '0' && *str <= '9') || *str == ',')
	{
		if (nb[i] > 255)
			break ;
		else if (*str == ',')
		{
			j++;
			i++;
			nb[i] = 0;
		}
		else
			nb[i]= (nb[i] * 10) + (*str - '0');
		str++;
	}
	if (*str || !nb[0] || !nb[1] || !nb[2] || (j != 2) || nb[i] > 255) // pb sur !nb
		return (0);
	return (1);
}
