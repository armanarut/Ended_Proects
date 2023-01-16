/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:53:13 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/22 23:56:06 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_temp(int fd, char *temp)
{
	char	*buff;
	int		len;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(temp, '\n') && len)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_str(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_temp(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(temp) - i + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, &temp[++i]);
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp[65536];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = get_temp(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	str = get_str(temp[fd]);
	temp[fd] = get_next_temp(temp[fd]);
	return (str);
}
