/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:52:06 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/13 19:12:15 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argc != 2 || i != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -2;
	while (i + 2 < 31)
	{
		i += 2;
		if ('1' <= argv[1][i] && argv[1][i] <= '4')
			if (argv[1][i + 1] == ' ' || i == 30)
				continue ;
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	ft_prtmtx(int mtx[][4][4], int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			ft_putchar(mtx[i][x][y] + 48);
			if (x != 3)
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
	}
}
