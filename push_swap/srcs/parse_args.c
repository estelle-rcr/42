/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:47:17 by erecuero          #+#    #+#             */
/*   Updated: 2021/05/29 16:34:58 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_extended(const char *str, t_vars *vars)
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
		str++;
	}
	if (nb > 2147483647 || nb < -2147483648)
		return (exit_free(vars));
	if (*str && (!(*str >= 9 && *str <= 13) || *str != 32))
		return (exit_free(vars));
	return ((int)nb * sign);
}
