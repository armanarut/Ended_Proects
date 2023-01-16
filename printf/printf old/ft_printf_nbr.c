/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:35:44 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/26 00:35:47 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char x)
{
	int	print_len;

	print_len = 0;
	if (!num)
		print_len += write (1, "0", 1);
	else
	{
		ft_putnbr_hex(num, x - 23);
		while (num)
		{
			print_len++;
			num = num / 16;
		}
	}
	return (print_len);
}

void	ft_putnbr_hex(unsigned long long nb, char a)
{
	int	nbr_out[20];
	int	i;

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb)
	{
		nbr_out[i++] = nb % 16;
		nb = nb / 16;
	}
	while (--i >= 0)
	{
		if (nbr_out[i] > 9)
			ft_putchar(a + nbr_out[i] - 10);
		else
			ft_putchar(nbr_out[i] + '0');
	}
}

int	ft_putptr(unsigned long long p)
{
	int	print_len;

	print_len = 0;
	if (!p)
		print_len += write (1, "0x0", 3);
	else
	{
		print_len += write (1, "0x", 2);
		ft_putnbr_hex(p, 'a');
		while (p)
		{
			print_len++;
			p = p / 16;
		}
	}
	return (print_len);
}

void	ft_getnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_getnbr(nbr / 10);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0');
}

int	ft_putnbr(int num)
{
	int	print_len;

	print_len = 0;
	if (!num)
		print_len += write (1, "0", 1);
	else
	{
		if (num < 0)
			print_len++;
		ft_getnbr(num);
		while (num)
		{
			print_len++;
			num = num / 10;
		}
	}
	return (print_len);
}
