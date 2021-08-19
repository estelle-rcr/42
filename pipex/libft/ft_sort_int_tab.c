/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:07:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 14:14:07 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	swap;
	int	i;

	count = 1;
	while (count < (size + 1))
	{
		swap = tab[count];
		i = count - 1;
		while (i >= 0 && tab[i] > swap)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = swap;
		count++;
	}
}
