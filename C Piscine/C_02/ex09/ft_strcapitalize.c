/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:36:29 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/10 21:50:07 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	s;

	i = -1;
	while (str[++i] != '\0')
	{
		s = str[i - 1];
		if (s < 48 || ('9' < s && s < 'A') || ('Z' < s && s < 'a') || ('z' < s))
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}
	return (str);
}
