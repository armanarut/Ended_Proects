/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:38:24 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/24 22:59:43 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_char_to_hex(char input, int rnd)
{
	int		i;
	char	hex[16];

	i = -1;
	while (++i < 16)
	{
		if (i < 10)
			hex[i] = i + 48;
		else
			hex[i] = i + 87;
	}
	if (input >= 16)
	{
		ft_char_to_hex(input / 16, 1);
		ft_char_to_hex(input % 16, 1);
	}
	else
	{
		if (rnd == 0)
			ft_putchar('0');
		ft_putchar(hex[input + '\0']);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] < 32 || 126 < str[i])
		{
			ft_putchar('\\');
			ft_char_to_hex(str[i], 0);
		}
		else
			ft_putchar(str[i]);
	}
}
