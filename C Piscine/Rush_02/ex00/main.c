/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:28:44 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/20 22:39:11 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fgen.h"

int	ft_atoi(char *str)
{
	int				i;
	int				n;
	long long int	num;

	n = 1;
	num = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -n;
	while (str[i++])
	{
		if (str[i - 1] < '0' || '9' < str[i - 1])
			break ;
		else
		{
			num = num * 10 + str[i - 1] - 48;
			if (num > 2000000000)
				ft_error();
		}
	}
	return (num * n);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = (char *) malloc(len + 1);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_list	*dict(char *file, int i)
{
	int		fd;
	char	c[1];
	t_list	*tab;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tab = (t_list *) malloc(16 * 33);
	if (fd == -1)
		exit(1);
	while (++i < 32)
	{
		tab[i].num = ft_atoi(ft_getnb(fd));
		read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		if (c[0] == ':')
			read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		tmp = ft_getval(fd, c);
		tab[i].text = ft_strdup(tmp);
		free(tmp);
	}
	close(fd);
	return (tab);
}

int	main(int ac, char **av)
{
	t_list	*list;
	int		*a;
	int		a1;

	a1 = 1;
	a = & a1;
	if (ac > 3 || ac == 1)
		ft_error();
	if (ac == 2)
	{
		ft_input_check(av[1]);
		list = dict("numbers.dict.txt", -1);
		ft_num_text(ft_atoi(av[1]), list, a);
	}
	ft_putstr("\n", 1);
	return (0);
}
