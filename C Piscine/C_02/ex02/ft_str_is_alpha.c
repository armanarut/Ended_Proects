/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:04:22 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/12 00:56:35 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < 'A' || ('Z' < str[i] && str[i] < 'a') || 'z' < str[i])
			return (0);
	return (1);
}
