/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:09:56 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 14:06:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (flag == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if (flag == 0 && str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		flag = 0;
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		{
			flag = 1;
		}
		i++;
	}
	return (str);
}
