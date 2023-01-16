/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:28:40 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:53:39 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_temp(char *temp)
{
	int	i;

	if (!temp)
		put_error("Incorrect map (NULL)");
	if (ft_strstr(temp, "\n\n") || temp[0] == '\n'
		|| temp[ft_strlen(temp) - 1] == '\n')
		put_error("Incorrect map (newlines)");
	if (ft_strchr(temp, 'P') != ft_strrchr(temp, 'P') || !ft_strchr(temp, 'E')
		|| !ft_strchr(temp, 'C'))
		put_error("Incorrect map (characters)");
	i = -1;
	while (temp[++i])
		if (temp[i] != '1' && temp[i] != '0' && temp[i] != 'P' && temp[i] != 'C'
			&& temp[i] != 'E' && temp[i] != 'K' && temp[i] != '\n')
			put_error("Incorrect map (other characters)");
}

void	check_maps(void)
{
	int	i;

	map.x = ft_strlen(map.maps[0]);
	map.y = 0;
	while (map.maps[++map.y])
		if ((int)ft_strlen(map.maps[map.y]) != map.x)
			put_error("Incorrect map (unequal)");
	if ((map.y < 4 && map.x < 4) || map.y + map.x < 8)
		put_error("Incorrect map (size)");
	i = -1;
	while (++i < map.x)
		if (map.maps[0][i] != '1' || map.maps[map.y - 1][i] != '1')
			put_error("Incorrect map (walls)");
	i = -1;
	while (++i < map.y)
		if (map.maps[i][0] != '1' || map.maps[i][map.x - 1] != '1')
			put_error("Incorrect map (walls)");
}

void	get_positions(void)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map.y)
	{
		i = -1;
		while (++i < map.x)
		{
			if (map.maps[j][i] == 'P')
			{
				player.x = i;
				player.y = j;
			}
		}
	}
}

void	get_map(char *filename)
{
	int		fd;
	char	*temp;
	char	*buff;

	fd = open(filename, O_RDONLY);
	temp = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		temp = ft_strjoin_free(temp, buff);
		free (buff);
		buff = get_next_line(fd);
	}
	check_temp(temp);
	map.maps = ft_split(temp, '\n');
	free(temp);
	close(fd);
	check_maps();
	get_positions();
}
