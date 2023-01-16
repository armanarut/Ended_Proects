/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:36:22 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/26 00:36:28 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_option
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		precision;
	int		flag_pre_va;
	int		num_m;
	char	type;
}				t_option;

int		ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr_hex(unsigned long long nb, char a);
int		ft_putptr(unsigned long long p);
void	ft_getnbr(int n);
int		ft_putnbr(int num);
void	ft_getnbr_unsigned(unsigned int nbr);
int		ft_putnbr_unsigned(unsigned int num);
int		ft_puthex(unsigned int num, char x);
int		ft_checkpercent(va_list args, const char c);
int		ft_printf(const char *str, ...);

#endif
