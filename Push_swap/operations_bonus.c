/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:05:20 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/07 00:07:17 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack)->next)
		return (0);
	node = (*stack)->next;
	(*stack)->next = node->next;
	node->next = *stack;
	*stack = node;
	return (1);
}

int	push(t_list **steck1, t_list **steck2)
{
	t_list	*node;

	node = *steck1;
	if (!node)
		return (0);
	*steck1 = node->next;
	node->next = *steck2;
	*steck2 = node;
	return (1);
}

int	rotate(t_list **stack)
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
	return (1);
}

int	reverse_rotate(t_list **stack)
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
	return (1);
}

int	operation(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp(str, "pb\n"))
		return (push(a, b));
	if (!ft_strcmp(str, "pa\n"))
		return (push(b, a));
	if (!ft_strcmp(str, "sa\n"))
		return (swap(a));
	if (!ft_strcmp(str, "sb\n"))
		return (swap(b));
	if (!ft_strcmp(str, "ss\n"))
		return (swap(a) + swap(b));
	if (!ft_strcmp(str, "ra\n"))
		return (rotate(a));
	if (!ft_strcmp(str, "rb\n"))
		return (rotate(b));
	if (!ft_strcmp(str, "rr\n"))
		return (rotate(a) + rotate(b));
	if (!ft_strcmp(str, "rra\n"))
		return (reverse_rotate(a));
	if (!ft_strcmp(str, "rrb\n"))
		return (reverse_rotate(b));
	if (!ft_strcmp(str, "rrr\n"))
		return (reverse_rotate(a) + reverse_rotate(b));
	ft_exit();
	return (0);
}
