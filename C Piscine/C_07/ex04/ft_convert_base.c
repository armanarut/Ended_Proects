/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:15:43 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/23 23:24:26 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check(char *base);
int		check_minus(long int *nb);
char	*ft_revers(int *nbr_out, char *base, int i, int x);
char	*ft_putnbr_base(long int nbr, char *base);

int	check_base(int ba, char *base)
{
	int	x;
	int	y;

	ba = 0;
	while (base[ba] != '\0')
		ba++;
	if (ba == 0 || ba == 1)
		return (0);
	x = 0;
	while (x < ba)
	{
		if (base[x] < 33 || base[x] > 126)
			return (0);
		if (base[x] == '-' || base[x] == '+')
			return (0);
		y = x;
		while (++y < ba)
		{
			if (base[x] == base[y])
				return (0);
		}
		x++;
	}
	return (ba);
}

int	srav_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (c == base[i])
			return (i);
	return (-1);
}

int	ft_atoi(char *str, char *base, int ba)
{
	int	min;
	int	i;
	int	rez;

	rez = 0;
	i = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -min;
	while (srav_base(str[i], base) != -1)
		rez = rez * ba + srav_base(str[i++], base);
	return (rez * min);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ba;

	ba = 0;
	ba = check_base(ba, base);
	if (ba == 0)
		return (0);
	return (ft_atoi(str, base, ba));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	num;

	if (check_base(0, base_from) && check_base(0, base_to))
	{
		num = ft_atoi_base (nbr, base_from);
		if (!nbr || !base_from || !base_to)
			return (0);
		return (ft_putnbr_base(num, base_to));
	}
	return (0);
}
