/* ************************************************************************** */
/*			                                                                */
/*			                                            :::      ::::::::   */
/*   utils.c			                                :+:      :+:    :+:   */
/*			                                        +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>			        +#+  +:+       +#+        */
/*			                                    +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:43:38 by akazarya		  #+#	#+#             */
/*   Updated: 2022/05/07 15:58:59 by akazarya         ###   ########.fr       */
/*			                                                                */
/* ************************************************************************** */

#include "push_swap.h"

int	my_atoi(const char *str)
{
	long int	num;
	int			i;
	int			n;

	num = 0;
	i = 0;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -n;
	if (str[i] < '0' || '9' < str[i])
		ft_exit();
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if ((n > 0 && num > INT_MAX) || (-num < INT_MIN))
			ft_exit();
	}
	return (num * n);
}

int	*ft_realloc_int(int *ptr, int size, int last_size)
{
	int	*new_ptr;
	int	i;

	new_ptr = malloc(sizeof(int) * size);
	if (!new_ptr)
		return (NULL);
	i = -1;
	while (++i < last_size)
		new_ptr[i] = ptr[i];
	free(ptr);
	return (new_ptr);
}

t_list	*ft_lstindex_last(t_list *lst, int i)
{
	int	len;

	if (!lst)
		return (0);
	len = ft_lstsize(lst);
	while (lst && len-- - i > 0)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstindex(t_list *lst, int i)
{
	if (!lst)
		return (0);
	while (lst && i-- > 0)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	printlist(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("% d", *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("  ");
		if (b)
		{
			ft_printf("  % d\n", *(int *)b->content);
			b = b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf(" a   b\n\n");
}
