/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:05:48 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/14 17:07:45 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "png/wall.xpm"
# define EXIT "png/exit.xpm"
# define COIN "png/coin/coin*.xpm"
# define PLAYA "png/player/player*.xpm"
# define FLOOR "png/floor.xpm"
# define KILL "png/kill.xpm"

# include "./libs/printf/ft_printf.h"
# include "./libs/minilibx_mms/mlx.h"

struct	s_map
{
	char	**maps;
	int		x;
	int		y;
}			map;

typedef struct s_image
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			data;

struct	s_player
{
	int	x;
	int	y;
}		player;

struct	s_temp
{
	int		x;
	int		y;
	int		size;
	int		step;
	char	*file;
	char	coin[19];
	char	playa[22];
	char	coin_count;
}			temp;

//maps
void	get_map(char *filename);

//images
void	get_img(void);

//keys
int	key_hook(int keycode);

//utils
void	put_error(char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
void	get_size(void);
int		close_prog(void);
void	congrats(void);
void	check_arg(int argc, char **argv);
int		check_null(void);
void	go_begin(void);
void	animation_count(void);

#endif
