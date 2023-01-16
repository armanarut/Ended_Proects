/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:48:55 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 15:57:55 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **argc)
{
	t_list	*a;
	int		*argint;
	int		i;
	int		len;

	if (argv <= 1)
		return (0);
	argint = argc_split(argv, argc, &len);
	a = NULL;
	i = -1;
	while (++i < len)
		ft_lstadd_back(&a, ft_lstnew(&argint[i]));
	checkerror(a);
	push_swap(a, NULL);
	free(argint);
	return (0);
}
