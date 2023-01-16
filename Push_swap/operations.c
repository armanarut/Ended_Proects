/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:05:22 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/06 23:07:25 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack, char *str)
{
	t_list	*node;

	if (!*stack || !(*stack)->next)
		return (0);
	node = (*stack)->next;
	(*stack)->next = node->next;
	node->next = *stack;
	*stack = node;
	if (str[0])
		ft_printf("%s\n", str);
	return (1);
}

int	push(t_list **steck1, t_list **steck2, char *str)
{
	t_list	*node;

	node = *steck1;
	if (!node)
		return (0);
	*steck1 = node->next;
	node->next = *steck2;
	*steck2 = node;
	ft_printf("%s\n", str);
	return (1);
}

int	rotate(t_list **stack, char *str)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *stack;
	if (!*stack || !node1->next)
		return (0);
	*stack = node1->next;
	node2 = ft_lstlast(node1);
	node2->next = node1;
	node1->next = NULL;
	if (str[0])
		ft_printf("%s\n", str);
	return (1);
}

int	reverse_rotate(t_list **stack, char *str)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *stack;
	if (!*stack || !node1->next)
		return (0);
	node2 = ft_lstlast(*stack);
	while (node1->next->next)
		node1 = node1->next;
	node1->next = NULL;
	node2->next = *stack;
	*stack = node2;
	if (str[0])
		ft_printf("%s\n", str);
	return (1);
}

int	operation(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp(str, "pb"))
		return (push(a, b, str));
	if (!ft_strcmp(str, "pa"))
		return (push(b, a, str));
	if (!ft_strcmp(str, "sa"))
		return (swap(a, str));
	if (!ft_strcmp(str, "sb"))
		return (swap(b, str));
	if (!ft_strcmp(str, "ss"))
		return (swap(a, str) + swap(b, ""));
	if (!ft_strcmp(str, "ra"))
		return (rotate(a, str));
	if (!ft_strcmp(str, "rb"))
		return (rotate(b, str));
	if (!ft_strcmp(str, "rr"))
		return (rotate(a, str) + rotate(b, ""));
	if (!ft_strcmp(str, "rra"))
		return (reverse_rotate(a, str));
	if (!ft_strcmp(str, "rrb"))
		return (reverse_rotate(b, str));
	if (!ft_strcmp(str, "rrr"))
		return (reverse_rotate(a, str) + reverse_rotate(b, ""));
	return (0);
}
