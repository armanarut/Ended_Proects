/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:33:24 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/28 19:36:36 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *err, char *cmd, int id)
{
	write(2, err, ft_strlen(err));
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	if (id)
		exit(1);
}

void	ft_my_strjoin(char **s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!str)
		return ;
	i = 0;
	while (i < ft_strlen(*s1))
	{
		str[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(*s1);
	*s1 = str;
}

char	*mini_get_next_line(int fd)
{
	char	temp;
	char	*line;
	int		edl;

	line = malloc(10000);
	while (1)
	{
		edl = read(fd, &temp, 1);
		if (!edl || temp == '\n')
			break ;
		ft_my_strjoin(&line, &temp);
	}
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)s - 1);
	if (!c && !*s)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
