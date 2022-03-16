/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:54:46 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/13 19:16:26 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str(int str[][4], int i, int n, int e[])
{
	while (++e[0] <= 4)
	{
		e[1] = 0;
		while (++e[1] <= 4)
		{
			if (e[1] == e[0])
				continue ;
			e[2] = 0;
			while (++e[2] <= 4)
			{
				if (e[2] == e[0] || e[2] == e[1])
					continue ;
				e[3] = 0;
				while (++e[3] <= 4)
				{
					if (e[3] == e[0] || e[3] == e[1] || e[3] == e[2])
						continue ;
					n = -1;
					while (++n < 4)
						str[i][n] = e[n];
					i++;
				}
			}
		}
	}
}

int	srav_el(int srav[4])
{
	if (srav[0] == 4)
		return (1);
	if (srav[0] == 3)
		return (2);
	if (srav[0] == 1 && srav[1] == 2 && srav[2] == 3)
		return (4);
	if (srav[0] == 1 && srav[1] == 2 && srav[2] == 4)
		return (3);
	if (srav[0] == 1 && srav[1] == 3)
		return (3);
	if (srav[0] == 1 && srav[1] == 4)
		return (2);
	if (srav[0] == 2 && srav[1] == 1 && srav[2] == 3)
		return (3);
	if (srav[0] == 2 && srav[1] == 1 && srav[2] == 4)
		return (2);
	if (srav[0] == 2 && srav[1] == 3)
		return (3);
	if (srav[0] == 2 && srav[1] == 4)
		return (2);
	return (0);
}

int	vokrug1(int col_tab[][4], int row_tab[][4], char *argv[])
{
	int		x[2];
	char	argv_str[33];

	x[0] = 0;
	x[1] = 0;
	while (x[0] < 15)
	{
		argv_str[x[0]] = col_tab[(x[0] - x[0] % 8) / 8][x[1]] + '0';
		argv_str[x[0] + 1] = 32;
		argv_str[x[0] + 16] = row_tab[(x[0] - x[0] % 8) / 8][x[1]] + '0';
		argv_str[x[0] + 17] = 32;
		x[0] += 2;
		x[1]++;
		if (x[1] == 4)
			x[1] = 0;
	}
	argv_str[32] = '\0';
	x[0] = -1;
	while (++x[0] < 31)
		if (argv[1][x[0]] != argv_str[x[0]])
			return (0);
	return (1);
}

int	vokrug(int mtx[][4][4], int i, char *argv[])
{
	int		x[2];
	int		col_tab[2][4];
	int		row_tab[2][4];
	int		srav[4][4];

	x[0] = -1;
	while (++x[0] < 4)
	{
		x[1] = -1;
		while (++x[1] < 4)
		{
			srav[0][x[1]] = mtx[i][x[0]][x[1]];
			srav[2][x[1]] = mtx[i][x[1]][x[0]];
			srav[1][x[1]] = mtx[i][x[0]][3 - x[1]];
			srav[3][x[1]] = mtx[i][3 - x[1]][x[0]];
		}
		col_tab[0][x[0]] = srav_el(srav[0]);
		row_tab[0][x[0]] = srav_el(srav[2]);
		col_tab[1][x[0]] = srav_el(srav[1]);
		row_tab[1][x[0]] = srav_el(srav[3]);
	}
	return (vokrug1(col_tab, row_tab, argv));
}
