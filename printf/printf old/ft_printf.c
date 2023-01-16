/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:43 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/15 22:11:58 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getnbr_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_getnbr_unsigned(nbr / 10);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0');
}

int	ft_putnbr_unsigned(unsigned int num)
{
	int	print_len;

	ft_getnbr_unsigned(num);
	print_len = 1;
	while (num)
	{
		if (num < 10)
			break ;
		print_len++;
		num = num / 10;
	}
	return (print_len);
}

int	ft_checkpercent(va_list args, const char c)
{
	int		print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_putchar(va_arg (args, int));
	else if (c == 's')
		print_len += ft_putstr(va_arg (args, char *));
	else if (c == 'p')
		print_len += ft_putptr(va_arg (args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += ft_putnbr(va_arg (args, int));
	else if (c == 'u')
		print_len += ft_putnbr_unsigned(va_arg (args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_len += ft_puthex(va_arg (args, unsigned int), c);
	else if (c == '%')
		print_len += write (1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	va_start(args, str);
	print_len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			print_len += ft_checkpercent (args, str[++i]);
		else
			print_len += ft_putchar(str[i]);
	}
	va_end(args);
	return (print_len);
}

// int	main()
// {
// 	// char str[] = "Arman\n";
// 	// char c = 'A';
// 	// char *p = &c;
// 	int	num = 4;
// 	printf("   printf: %d;\n",    printf("out: %9.d;\n", num));
// 	//printf("ft_printf: %d;\n", ft_printf("out: %p;\n", -2));
// }
