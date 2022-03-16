/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:03:39 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/05 17:48:27 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_matrix(int x, int y, int xx, int yy)
{
	if ((xx == 0 || yy == 0) || (xx == x || yy == y))
	{
		if ((xx == 0 && yy == 0) || (xx == x && yy == y && x != 0 && y != 0))
			ft_putchar ('/');
		else if ((xx == x && yy == 0) || (xx == 0 && yy == y))
			ft_putchar ('\\');
		else
			ft_putchar ('*');
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

b = a ==42 ? 1 : 0;