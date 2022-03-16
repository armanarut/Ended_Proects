/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:38:50 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/20 22:39:03 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fgen.h"

long long int	getdec(long long int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

long long int	getmult(long long int nb)
{	
	if (nb >= 1000000000000)
		return (1000000000000);
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}

char	*ft_getnb(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = (char *) malloc(128);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*ft_getval(int fd, char *c)
{
	int		i;
	char	*str;

	str = (char *) malloc(128);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

void	ft_num_text(long long int nb, t_list *list, int *a)
{
	int				i;
	long long int	m;

	i = 0;
	m = getmult(nb);
	if (m >= 100)
		ft_num_text(nb / m, list, a);
	if (*a == 0)
		write(1, " ", 1);
	*a = 0;
	while (list[i].num != m)
		i++;
	ft_putstr(list[i].text, 1);
	if (m != 0 && nb % m != 0)
		ft_num_text(nb % m, list, a);
}
