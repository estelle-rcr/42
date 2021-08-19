/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:50:08 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/19 16:44:23 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_join_path(char const *s1, char c, char const *s2)
{
	char	*tab;
	int		size1;
	int		size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	tab = malloc((size1 + size2 + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_memmove(tab, s1, size1);
	ft_memmove(tab + size1, &c, 1);
	ft_memmove(tab + size1 + 1, s2, size2);
	tab[size1 + size2 + 1] = '\0';
	return (tab);
}
