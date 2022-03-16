/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:14:39 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/23 00:26:03 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(dest);
	if (size <= j)
		return (ft_strlen(src) + size);
	while (j + 1 < size && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (ft_strlen(&src[i]) + ft_strlen(dest));
}
