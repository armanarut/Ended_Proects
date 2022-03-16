/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:10:42 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/23 23:24:31 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	check_minus(long int *nb)
{
	if (*nb < 0)
	{
		*nb = -*nb;
		return (1);
	}
	return (0);
}

char	*ft_revers(int *nbr_out, char *base, int i, int x)
{
	char	*out;
	int		j;

	out = malloc(i + x + 2);
	if (!out)
		return (0);
	j = x;
	if (x == 1)
		out[0] = '-';
	while (--i >= 0)
	{
		out[j++] = base[nbr_out[i]];
	}
	return (out);
}

char	*ft_putnbr_base(long int nbr, char *base)
{
	long int	nb;
	int			nbr_out[50];
	int			size;
	int			i;
	int			x;

	if (ft_check(base))
	{
		i = 0;
		size = 0;
		while (base[size])
			size++;
		nb = nbr;
		x = check_minus(&nb);
		if (nb == 0)
			nbr_out[i++] = 0;
		while (nb)
		{
			nbr_out[i++] = nb % size;
			nb = nb / size;
		}
		return (ft_revers(nbr_out, base, i, x));
	}
	return (0);
}
