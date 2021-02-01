/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:20:11 by erecuero          #+#    #+#             */
/*   Updated: 2020/11/18 18:20:13 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (0);
}
