/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:56:19 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:04:55 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(void)
{
	char	str[21];
	char	*num;

	mlx_destroy_image(data.mlx, data.img);
	get_img();
	num = ft_itoa(temp.step);
	mlx_string_put(data.mlx, data.win, temp.size / 5, temp.size / 5, 0xFF11111,
		ft_strcat(ft_strcat(str, "steps: "), num));
	free(num);
	mlx_do_sync(data.mlx);
	return (0);
}

void	so_long(void)
{
	get_size();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map.x * temp.size, map.y * temp.size,
			"so_long_akazarya");
	animation_count();
	get_img();
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 0, close_prog, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	check_arg(argc, argv);
	temp.file = argv[1];
	get_map(temp.file);
	so_long();
	return (0);
}
