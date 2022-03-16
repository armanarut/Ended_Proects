/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:11:15 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/13 19:08:55 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_prtmtx(int mtx[][4][4], int i);
int		ft_check(int argc, char *argv[]);
int		srav_el(int srav[4]);
int		vokrug(int mtx[][4][4], int i, char *argv[]);
void	ft_str(int str[][4], int i, int n, int e[]);

int	ft_mtx3(int str[][4], int i[], int e[], char *argv[])
{	
	int	mtx[576][4][4];

	while (++i[1] < 4)
	{
		i[2] = -1;
		while (++i[2] < 4)
			mtx[i[0]][i[1]][i[2]] = str[e[i[1]]][i[2]];
	}
	if (vokrug(mtx, i[0], argv) == 1)
	{
		ft_prtmtx(mtx, i[0]);
		return (0);
	}
	return (1);
}

int	ft_mtx2(int str[][4], int i[], int e[], char *argv[])
{				
	while (++e[3] < 24)
	{
		i[1] = -1;
		while (++i[1] < 3)
		{
			i[2] = -1;
			while (++i[2] < 4)
				if (str[e[3]][i[2]] == str[e[i[1]]][i[2]])
					i[3] = 0;
		}
		if (i[3]++ == 0)
			continue ;
		i[1] = -1;
		if (ft_mtx3(str, i, e, argv) == 0)
			return (0);
		i[0]++;
	}
	return (1);
}

int	ft_mtx1(int str[][4], int i[], int e[], char *argv[])
{
	e[2] = -1;
	while (++e[2] < 24)
	{
		i[1] = -1;
		while (++i[1] < 2)
		{
			i[2] = -1;
			while (++i[2] < 4)
				if (str[e[2]][i[2]] == str[e[i[1]]][i[2]])
					i[3] = 0;
		}
		if (i[3]++ == 0)
			continue ;
		e[3] = -1;
		if (ft_mtx2(str, i, e, argv) == 0)
			return (0);
	}
	return (1);
}

int	ft_mtx(char *argv[])
{
	int	i[4];
	int	e[4];
	int	str[24][4];

	e[0] = 0;
	ft_str(str, 0, 0, e);
	e[0] = -1;
	i[0] = 0;
	while (++e[0] < 24)
	{
		e[1] = -1;
		while (++e[1] < 24)
		{
			i[2] = -1;
			while (++i[2] < 4)
				if (str[e[1]][i[2]] == str[e[0]][i[2]])
					i[3] = 0;
			if (i[3]++ == 0)
				continue ;
			if (ft_mtx1(str, i, e, argv) == 0)
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (ft_check(argc, argv) == 0)
		return (0);
	if (ft_mtx(argv) == 0)
		return (0);
	write(1, "Error\n", 6);
	return (0);
}
