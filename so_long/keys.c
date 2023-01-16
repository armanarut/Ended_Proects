/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:29:00 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:29:01 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_down(void)
{
	if (map.maps[player.y + 1][player.x] != '1')
	{
		player.y++;
		if (map.maps[player.y][player.x] == 'C')
			map.maps[player.y][player.x] = '0';
		if (map.maps[player.y][player.x] == 'E' && check_null())
			congrats();
		if (map.maps[player.y][player.x] == 'K')
			go_begin();
		get_img();
		return (1);
	}
	return (0);
}

int	key_up(void)
{
	if (map.maps[player.y - 1][player.x] != '1')
	{
		player.y--;
		if (map.maps[player.y][player.x] == 'C')
			map.maps[player.y][player.x] = '0';
		if (map.maps[player.y][player.x] == 'E' && check_null())
			congrats();
		if (map.maps[player.y][player.x] == 'K')
			go_begin();
		get_img();
		return (1);
	}
	return (0);
}

int	key_left(void)
{
	if (map.maps[player.y][player.x - 1] != '1')
	{
		player.x--;
		if (map.maps[player.y][player.x] == 'C')
			map.maps[player.y][player.x] = '0';
		if (map.maps[player.y][player.x] == 'E' && check_null())
			congrats();
		if (map.maps[player.y][player.x] == 'K')
			go_begin();
		get_img();
		return (1);
	}
	return (0);
}

int	key_right(void)
{
	if (map.maps[player.y][player.x + 1] != '1')
	{
		player.x++;
		if (map.maps[player.y][player.x] == 'C')
			map.maps[player.y][player.x] = '0';
		if (map.maps[player.y][player.x] == 'E' && check_null())
			congrats();
		if (map.maps[player.y][player.x] == 'K')
			go_begin();
		get_img();
		return (1);
	}
	return (0);
}

int	key_hook(int keycode)
{
	if (keycode == 0 && key_left())
		temp.step++;
	else if (keycode == 1 && key_down())
		temp.step++;
	else if (keycode == 2 && key_right())
		temp.step++;
	else if (keycode == 13 && key_up())
		temp.step++;
	else if (keycode == 53)
		close_prog();
	return (0);
}
