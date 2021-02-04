/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:55:32 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/04 17:23:23 by erecuero         ###   ########.fr       */
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
