/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:58:34 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/19 17:44:50 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putch(int *ch)
{
	int	i;

	i = -1;
	while (++i <= 9)
		ft_putchar(ch[i] + '0');
	ft_putchar('\n');
}

int	test_ch(int *ch, int n, int i)
{
	int	j;

	j = -1;
	while (++j < n)
		if (ch[j] + j == n + i || j - ch[j] == n - i || i == ch[j])
			return (0);
	return (1);
}

void	make_ch(int *ch, int *count, int n)
{
	int	i;

	if (n == 10)
	{
		*count += 1;
		ft_putch(ch);
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (test_ch(ch, n, i))
			{
				ch[n] = i;
				make_ch(ch, count, n + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	count;
	int	ch[10];

	i = -1;
	while (++i < 10)
		ch[i] = -1;
	count = 0;
	make_ch(ch, &count, 0);
	return (count);
}
