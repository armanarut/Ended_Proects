/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:17:38 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/08 22:09:29 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_put_comma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_make_char(int *array, int n, int x, int d)
{
	int	max_d;

	while (++x < n)
		array[x] = x;
	while (x > 0)
	{
		max_d = 10;
		x = -1;
		while (++x < n)
			ft_putchar(array[x] + '0');
		x = n;
		while (x--)
		{
			d = array[x];
			if (d < --max_d)
			{
				while (x < n)
					array[x++] = ++d;
				ft_put_comma();
				break ;
			}
		}
	}
}

void	ft_print_combn(int n)
{
	int	array[10];
	int	x;
	int	d;

	d = 0;
	if (n <= 0 || n > 10)
		return ;
	else
	{
		x = -1;
		ft_make_char (array, n, x, d);
	}
}
