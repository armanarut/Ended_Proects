/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:03:52 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 15:55:14 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_2(t_list **a, t_list **b)
{
	while (checklist_a(*a))
	{
		if (checkmax(*a, l_data(*a)))
			operation(a, b, "ra");
		else if (checkmax(*a, l_data((*a)->next)))
			operation(a, b, "rra");
		if (l_data(*a) > l_data((*a)->next))
			operation(a, b, "sa");
	}
}

void	push_swap_min(t_list **a, t_list **b)
{
	while (checklist_a(*a))
	{
		while (checkmin(*a, l_data(*a)))
			operation(a, b, "pb");
		if (ft_lstsize(*a) == 3)
			push_swap_2(a, b);
		else if (checkfindmin(*a) == 1)
			while (!checkmin(*a, l_data(*a)))
				operation(a, b, "ra");
		else
			while (!checkmin(*a, l_data(*a)))
				operation(a, b, "rra");
	}
	while (*b)
		operation(a, b, "pa");
}

void	push_swap_1(t_list **a, t_list **b)
{
	if (!checklist_a(*a))
		return ;
	while (*a)
	{
		compare_chose(a, b);
		if (*b && (*b)->next && check_find_compare(l_data(*a), *b) == 1)
			while (!check_compare(l_data(*a), *b))
				operation(a, b, "rb");
		else if (*b && (*b)->next && check_find_compare(l_data(*a), *b) == 2)
			while (!check_compare(l_data(*a), *b))
				operation(a, b, "rrb");
		operation(a, b, "pb");
	}
	if (*b && (*b)->next && checkfindmin(*b) == 1)
		while (!checkmax(*b, l_data(*b)))
			operation(a, b, "rb");
	else if (*b && (*b)->next)
		while (!checkmax(*b, l_data(*b)))
			operation(a, b, "rrb");
	while (*b)
		operation(a, b, "pa");
}

void	push_swap(t_list *a, t_list *b)
{
	if (ft_lstsize(a) > 15)
		push_swap_1(&a, &b);
	else if (ft_lstsize(a) > 3)
		push_swap_min(&a, &b);
	else
		push_swap_2(&a, &b);
	ft_free_list(a);
}
