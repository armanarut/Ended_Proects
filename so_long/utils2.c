/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:29:15 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:29:20 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		put_error("Not correct input");
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber"))
		put_error("The map is not in \".ber\" format");
}

int	check_null(void)
{
	int	j;

	j = -1;
	while (++j < map.y)
		if (ft_strchr(map.maps[j], 'C'))
			return (0);
	return (1);
}

void	go_begin(void)
{
	get_map(temp.file);
	temp.step = -1;
}

void	animation_count(void)
{
	static char	count;
	static int	i;

	ft_strcpy(temp.coin, COIN);
	ft_strcpy(temp.playa, PLAYA);
	if (count < '0')
	count = '0';
	if (!(++i % 2) && (++count > '5' || count < '0'))
	count = '0';
	temp.coin[13] = count;
	temp.playa[17] = count;
}
