/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:07:55 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/06 23:09:56 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checklist_a(t_list *a)
{
	t_list	*a1;
	t_list	*a2;

	if (!a)
		return (0);
	a1 = a;
	while (a1->next)
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

int	checkmin(t_list *a, int num)
{
	t_list	*a1;

	a1 = a;
	while (a1)
	{
		if (num > l_data(a1))
			return (0);
		a1 = a1->next;
	}
	return (1);
}

int	checkmax(t_list *a, int num)
{
	t_list	*a1;

	a1 = a;
	while (a1)
	{
		if (num < l_data(a1))
			return (0);
		a1 = a1->next;
	}
	return (1);
}

int	findmin(t_list *a)
{
	t_list	*a1;
	t_list	*a2;
	int		x;
	int		i;

	i = 0;
	a1 = a;
	while (a1)
	{
		i++;
		x = 1;
		a2 = a;
		while (a2)
		{
			if (l_data(a1) > l_data(a2))
				x = 0;
			a2 = a2->next;
		}
		if (x)
			return (i);
		a1 = a1->next;
	}
	return (-1);
}

int	checkfindmin(t_list *a)
{
	int	len;
	int	i;

	len = ft_lstsize(a);
	i = findmin(a);
	if (len / i >= 2)
		return (1);
	return (2);
}
