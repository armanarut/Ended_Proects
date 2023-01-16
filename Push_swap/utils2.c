/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:02:23 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 00:02:25 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit (0);
}

int	l_data(t_list *stack)
{
	int	*num;

	num = stack->content;
	return (*num);
}

void	ft_free_list(t_list *lst)
{
	t_list	*new;

	while (lst)
	{
		new = lst->next;
		free(lst);
		lst = new;
	}
}

void	checkerror(t_list *a)
{
	t_list	*a1;
	t_list	*a2;

	a1 = a;
	while (a1->next)
	{
		a2 = a1->next;
		while (a2)
		{
			if (l_data(a1) == l_data(a2))
				ft_exit();
			a2 = a2->next;
		}
		a1 = a1->next;
	}
}

int	*argc_split(int argv, char **argc, int *len)
{
	int		i[3];
	char	**ac;
	int		*argint;

	i[0] = 0;
	i[2] = 0;
	*len = 0;
	argint = malloc(sizeof(int));
	if (!argint)
		return (0);
	while (++i[0] < argv)
	{
		ac = ft_split(argc[i[0]], ' ');
		i[1] = -1;
		while (ac[++i[1]])
			*len += 1;
		argint = ft_realloc_int(argint, *len, *len - i[1]);
		i[1] = -1;
		while (ac[++i[1]])
			argint[i[2]++] = my_atoi(ac[i[1]]);
		while (i[1]-- != -1)
			free(ac[i[1] + 1]);
		free(ac);
	}
	return (argint);
}
