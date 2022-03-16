/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:14:29 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/11 21:45:05 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_str_is_printable(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{	
		if (str[i] < 32 || 126 < str[i])
			return (0);
	}
	return (1);
}
