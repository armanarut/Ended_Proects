/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:04:54 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/28 20:04:55 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
			if (to_find[j++ + 1] == '\0')
				return (&str[i]);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			n = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;
	unsigned int	size;
	unsigned int	m;

	size = 0;
	while (s[size])
		size++;
	if (size + 1 < start)
		m = 1;
	else if (size - start + 1 > len)
		m = len + 1;
	else
		m = size - start + 1;
	s1 = malloc(m);
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len && start + i < size)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
