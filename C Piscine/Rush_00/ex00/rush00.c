/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:03:39 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/05 18:14:52 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_matrix(int x, int y, int xx, int yy)
{
	if ((xx == 0 || yy == 0) || (xx == x || yy == y))
	{
		if ((xx == 0 && yy == 0) || (xx == x && yy == y))
			ft_putchar ('o');
		else if ((xx == x && yy == 0) || (xx == 0 && yy == y))
			ft_putchar ('o');
		else if (xx == 0 || xx == x)
			ft_putchar ('|');
		else
			ft_putchar ('-');
	}
	else
		ft_putchar (' ');
}

void	rush(int x, int y)
{
	int	xx;
	int	yy;

	x = x - 1;
	y = y - 1;
	yy = -1;
	while (++yy <= y)
	{
		xx = -1;
		while (++xx <= x)
			print_matrix (x, y, xx, yy);
		ft_putchar ('\n');
	}
}
