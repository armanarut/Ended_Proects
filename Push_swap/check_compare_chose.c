/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compare_chose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:54:52 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/06 23:00:02 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_tab1(t_list *a, t_list *b, int len)
{
	int	*tab;
	int	i;

	tab = ft_calloc(len, sizeof(int));
	i = -1;
	while (++i < len)
	{
		tab[i] = i + check_compare_chose(a, b);
		a = a->next;
	}
	return (tab);
}

int	check_compare_chose1(t_list *a, t_list *b, int *i)
{
	int	*tab;
	int	j;
	int	x;
	int	len;

	len = ft_lstsize(a);
	tab = get_tab1(a, b, len);
	*i = -1;
	while (++*i < len)
	{
		x = 1;
		j = -1;
		while (++j < len)
			if (tab[*i] > tab[j])
				x = 0;
		if (x)
			break ;
	}
	x = tab[*i];
	if (tab)
		free(tab);
	return (x);
}

int	*get_tab2(t_list *a, t_list *b, int len)
{
	int	*tab;
	int	i;

	tab = ft_calloc(len, sizeof(int));
	i = 0;
	tab[i] = check_compare_chose(a, b);
	while (++i < len)
		tab[i] = i + check_compare_chose(ft_lstindex_last(a, i), b);
	return (tab);
}

int	check_compare_chose2(t_list *a, t_list *b, int *i)
{
	int	*tab;
	int	j;
	int	x;
	int	len;

	len = ft_lstsize(a);
	tab = get_tab2(a, b, len);
	*i = -1;
	while (++*i < len)
	{
		x = 1;
		j = -1;
		while (++j < len)
			if (tab[*i] > tab[j])
				x = 0;
		if (x)
			break ;
	}
	x = tab[*i];
	if (tab)
		free(tab);
	return (x);
}

void	compare_chose(t_list **a, t_list **b)
{
	int	up;
	int	down;

	if (!*b)
		return ;
	if (check_compare_chose1(*a, *b, &up) < check_compare_chose2(*a, *b, &down))
	{
		if (*b && check_find_compare(l_data(ft_lstindex(*a, up)), *b) == 1)
			while (!check_compare(l_data(ft_lstindex(*a, up)), *b) && up--)
				operation(a, b, "rr");
		while (up-- > 0)
			operation(a, b, "ra");
	}
	else
	{
		if (*b
			&& check_find_compare(l_data(ft_lstindex_last(*a, down)), *b) == 2)
			while (!check_compare(l_data(ft_lstindex_last(*a, down)), *b)
				&& down--)
				operation(a, b, "rrr");
		while (down-- > 0)
			operation(a, b, "rra");
	}
}
