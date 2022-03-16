/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:29:02 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/19 01:54:39 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		ft_putchar(str[i]);
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			n = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*c;

	i = 0;
	while (++i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			c = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = c;
			i = 0;
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
