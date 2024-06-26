/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:22:25 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/13 20:37:48 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strupcase(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{	
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	return (str);
}
