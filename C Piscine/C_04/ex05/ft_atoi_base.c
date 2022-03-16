/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:28:53 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/17 23:29:34 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_n[100];

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		if (base[i] < 33 || base[i] > 126)
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	ft_check_str(char *str, char *base, int i, int k)
{
	int	j;

	j = -1;
	while (base[++j])
	{
		if (str[i] == base[j])
		{
			g_n[k] = j;
			return (1);
		}
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int p, int k)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			p = -p;
	while (str[i])
	{
		if (ft_check_str(str, base, i, k) != 1)
			break ;
		k++;
		i++;
	}
	if (p < 0)
		return (-k);
	return (k);
}

int	ft_atoi_base(char *str, char *base)
{	
	int	j;
	int	size;
	int	p;
	int	num;
	int	k;

	if (ft_check_base(base))
	{
		size = 0;
		p = 1;
		while (base[size])
			size++;
		k = ft_atoi(str, base, p, 0);
		if (k < 0)
		{
			p = -1;
			k = -k;
		}
		num = 0;
		j = -1;
		while (++j < k)
			num = num * size + g_n[j];
		return (num * p);
	}
	return (0);
}