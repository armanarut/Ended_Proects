/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:49:38 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/18 01:48:49 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int			i;
	int			n;
	long int	num;

	n = 1;
	num = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -n;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			break ;
		else
			num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * n);
}
