/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:10:17 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 15:56:22 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "./printf/ft_printf.h"

int		operation(t_list **a, t_list **b, char *str);
void	push_swap(t_list *a, t_list *b);

//checks
int		checklist_a(t_list *a);
int		checkmin(t_list *a, int num);
int		checkmax(t_list *a, int num);
int		checkfindmin(t_list *a);

//check compare
void	compare_chose(t_list **a, t_list **b);
int		check_find_compare(int num, t_list *b);
int		find_compare(int num, t_list *b);
int		check_compare_chose(t_list *a, t_list *b);
int		check_compare(int num, t_list *b);

//utils
void	checkerror(t_list *a);
int		*argc_split(int argv, char **argc, int *len);
int		my_atoi(const char *str);
int		*ft_realloc_int(int *ptr, int size, int last_size);
void	ft_free_list(t_list *lst);
int		l_data(t_list *stack);
void	ft_exit(void);
t_list	*ft_lstindex_last(t_list *lst, int i);
t_list	*ft_lstindex(t_list *lst, int i);

void	printlist(t_list *a, t_list *b);

#endif
