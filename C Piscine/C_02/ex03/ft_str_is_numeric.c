/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:43:03 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/12 00:57:23 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || '9' < str[i])
			return (0);
	return (1);
}
