/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:41:54 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/23 23:28:05 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = -1;
	while (src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strmake(int size, char **strs, char *sep, char *str)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i < size)
			ft_strcat(str, sep);
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	if (size == 0)
	{
		str = malloc(1);
		return (str);
	}
	i = 0;
	len = (size - 1) * ft_strlen(sep);
	while (i < size)
		len += ft_strlen(strs[i++]);
	str = malloc(len);
	str[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i < size)
			ft_strcat(str, sep);
	}
	str[len] = '\0';
	return (str);
}
