/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:48:09 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/17 23:20:54 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] < 33 || base[i] > 126)
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

void	check_minus(long int *nb)
{
	if (*nb < 0)
	{
		ft_putchar('-');
		*nb = -*nb;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			nbr_out[50];
	int			size;
	int			i;

	if (ft_check(base))
	{
		i = 0;
		size = 0;
		while (base[size])
			size++;
		nb = nbr;
		check_minus(&nb);
		if (nb == 0)
			ft_putchar(base[0]);
		while (nb)
		{
			nbr_out[i++] = nb % size;
			nb = nb / size;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_out[i]]);
	}
}
