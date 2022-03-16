/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:01:53 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/12 00:56:16 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < 'A' || 'Z' < str[i])
			return (0);
	return (1);
}
