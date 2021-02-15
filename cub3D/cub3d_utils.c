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

int	ft_atoi_exit(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		if (nb < 0 && sign == 1)
			return (-1);
		else if (nb < 0 && sign == -1)
			return (0);
		str++;
	}
	nb = is_integer(nb, *str);
	return ((int)nb * sign);
}

long	is_integer(long n, char next)
{
	if (ft_isascii(next) && !ft_isdigit(next))
		return (0);
	else if (nb > 2147483647 || nb < -2147483648)
		return (0);
	else
		return (n);
}
