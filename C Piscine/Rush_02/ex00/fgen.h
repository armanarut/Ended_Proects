/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgen.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:45:25 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/20 22:50:12 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FGEN_H
# define FGEN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int		num;
	char	*text;
}		t_list;

t_list			*dict(char *file, int i);
long long int	getdec(long long int nb);
long long int	getmult(long long int nb);

int				ft_atoi(char *str);
char			*ft_strdup(char *src);
char			*ft_getnb(int fd);
char			*ft_getval(int fd, char *c);
void			ft_num_text(long long int nb, t_list *list, int *a);
void			ft_putstr(char *str, int fd);
void			ft_putchar(char c, int fd);
void			ft_putnbr(int nb, int fd);
void			ft_error(void);
void			ft_input_check(char *av);

#endif
