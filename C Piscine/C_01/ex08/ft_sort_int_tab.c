/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:55:25 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/09 22:37:50 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	num;
	int	size1;

	num = 0;
	size1 = size;
	while (--size1 > 0)
	{
		if (tab[size1] < tab[size1 - 1])
		{
				num = tab[size1 - 1];
				tab[size1 - 1] = tab[size1];
				tab[size1] = num;
		}
	}
	size1 = size;
	while (--size1 > 0)
		if (tab[size1] < tab[size1 - 1])
			ft_sort_int_tab(tab, size);
}
