/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:29:08 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:29:09 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(1);
}

char	*ft_strjoin_free(char *s1, char const *s2)
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
	if (s1)
		free(s1);
	return (str);
}

void	get_size(void)
{
	temp.size = 50;
	if (map.x > 41 && map.y > 20)
	{
		if (41 / map.x > 20 / map.y)
			temp.size = temp.size * 41 / map.x;
		else
			temp.size = temp.size * 20 / map.y;
	}
	else if (map.x > 41)
		temp.size = temp.size * 41 / map.x;
	else if (map.y > 20)
		temp.size = temp.size * 20 / map.y;
}

int	close_prog(void)
{
	mlx_destroy_window(data.mlx, data.win);
	free(map.maps);
	exit(0);
	return (0);
}

void	congrats(void)
{
	ft_printf("Congrats! your steps count: %d\n", ++temp.step);
	close_prog();
}
