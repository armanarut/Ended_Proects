/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:49:39 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/09 22:51:25 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	num;
	int	r;
	int	l;

	l = 0;
	r = size - 1;
	while (l < size / 2)
	{
		num = tab[r];
		tab[r--] = tab[l];
		tab[l++] = num;
	}
}
