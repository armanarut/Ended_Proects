/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:54:08 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/06 22:54:28 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_compare(int num, t_list *b)
{
	t_list	*b1;
	int		i;

	i = 0;
	b1 = b;
	b = b->next;
	while (b)
	{
		i++;
		if ((checkmin(b, num) && checkmin(b, l_data(b1)))
			|| (checkmax(b, num) && checkmax(b, l_data(b)))
			|| (num < l_data(b1) && num > l_data(b)))
			return (i);
		b1 = b;
		b = b->next;
	}
	return (1);
}

int	check_find_compare(int num, t_list *b)
{
	int	len;
	int	i;

	if (!b || check_compare(num, b))
		return (0);
	len = ft_lstsize(b);
	i = find_compare(num, b);
	if (len / i >= 2)
		return (1);
	return (2);
}

int	check_compare(int num, t_list *b)
{
	t_list	*b1;

	b1 = ft_lstlast(b);
	if ((checkmin(b, num) && checkmin(b, l_data(b1)))
		|| (checkmax(b, num) && checkmax(b, l_data(b)))
		|| (num < l_data(b1) && num > l_data(b)))
		return (1);
	return (0);
}

int	check_compare_chose(t_list *a, t_list *b)
{
	int	len;
	int	i;

	if (!b || check_compare(l_data(a), b))
		return (0);
	len = ft_lstsize(b);
	i = find_compare(l_data(a), b);
	if (len / i >= 2)
		return (i);
	return (len - i);
}
