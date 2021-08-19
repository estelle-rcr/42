/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:08:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 14:02:28 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[++length])
	{
	}
	while (str[i])
	{
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == length)
				return (&str[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
