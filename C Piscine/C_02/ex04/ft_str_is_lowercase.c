/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:50:46 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/11 21:44:05 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;
	int		n;
	char	a;

	i = -1;
	while (str[++i] != '\0')
	{	
		n = 0;
		a = 'a';
		while (a <= 'z')
			if (a++ == str[i])
				n++;
		if (n == 0)
			return (0);
	}
	return (1);
}
