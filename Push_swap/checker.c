/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:08:34 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 00:09:44 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checklist(t_list *a)
{
	t_list	*a1;
	t_list	*a2;

	a1 = a;
	while (a && a1->next)
	{
		a2 = a1->next;
		while (a2)
		{
			if (l_data(a1) > l_data(a2))
				return (1);
			a2 = a2->next;
		}
		a1 = a1->next;
	}
	return (0);
}

void	checker(t_list *a, t_list *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		operation(&a, &b, str);
		free(str);
	}
	if (!checklist(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_list(a);
}

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
	checker(a, NULL);
	free(argint);
	return (0);
}
