/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:55:32 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/10 23:19:49 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**free_tab(char **tab, int i)
{
	while (i--)
		free((void *)tab[i]);
	free((void *)tab);
	return (NULL);
}

int		count_elements(char **params)
{
	int i;

	while (params[i])
		i++;
	return (i);
}

int	ft_isnum(int i)
{
	while (i)
	{
		i /= 10;
		if (i >= '0' && i <= '9')
			return (1);
	}
	return (0);
}

