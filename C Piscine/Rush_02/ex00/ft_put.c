/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:52:45 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/20 22:53:49 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fgen.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int nb, int fd)
{
	long int	nbr;

	nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, fd);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0', fd);
}

void	ft_error(void)
{
	ft_putstr("Error\n", 1);
	exit (1);
}

void	ft_input_check(char *av)
{
	if (ft_atoi(av) < 0)
		ft_error();
}
