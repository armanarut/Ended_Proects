/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:31:41 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/10 01:31:43 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
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
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-1);
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (-1);
		else
			num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * n);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	write_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long	td(t_data *data, long last)
{
	return (get_time() - data->now - last);
}
