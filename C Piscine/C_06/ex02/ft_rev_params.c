/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:55:51 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/15 22:06:56 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc;
	while (1 <= --j)
	{
		i = -1;
		while (argv[j][++i] != '\0')
			ft_putchar(argv[j][i]);
		ft_putchar('\n');
	}
	return (0);
}
