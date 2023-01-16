/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:28:51 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:28:52 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	pixel_color(t_image image, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = image.addr + (y * image.line_length + x * (image.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	draw_image(int x, int y, char *file)
{
	t_image	image;
	int		i;
	int		j;

	image.img = mlx_xpm_file_to_image(data.mlx, file, &temp.x, &temp.y);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	j = -1;
	while (++j < temp.size)
	{
		i = -1;
		while (++i < temp.size)
		{
			if (pixel_color(image, i * temp.x / temp.size,
					j * temp.y / temp.size) == 0xff000000)
				continue ;
			my_mlx_pixel_put(x * temp.size + i, y * temp.size + j,
				pixel_color(image, i * temp.x / temp.size,
					j * temp.y / temp.size));
		}
	}
}

void	print_map(void)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map.y)
	{
		i = -1;
		while (++i < map.x)
		{
			if (map.maps[j][i] == '0' || map.maps[j][i] == 'P'
					|| map.maps[j][i] == 'C'
				|| map.maps[j][i] == 'E' || map.maps[j][i] == 'K')
				draw_image(i, j, FLOOR);
			if (map.maps[j][i] == '1')
				draw_image(i, j, WALL);
			if (map.maps[j][i] == 'C')
				draw_image(i, j, temp.coin);
			if (map.maps[j][i] == 'E')
				draw_image(i, j, EXIT);
			if (map.maps[j][i] == 'K')
				draw_image(i, j, KILL);
		}
	}
	draw_image(player.x, player.y, temp.playa);
}

void	get_img(void)
{
	data.img = mlx_new_image(data.mlx, map.x * temp.size, map.y * temp.size);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	animation_count();
	print_map();
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
}
