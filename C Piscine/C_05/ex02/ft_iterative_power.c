/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:20:31 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/17 19:49:03 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	num = 1;
	if (power == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	else
		while (power--)
			num = num * nb;
	return (num);
}
