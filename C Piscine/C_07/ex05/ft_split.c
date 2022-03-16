/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:50:19 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/23 00:18:24 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_chech_charset(int *i, char *str, char *charset, int *num)
{
	int	j;
	int	n;

	n = 0;
	j = -1;
	while (charset[++j])
	{
		if (str[*i] == charset[j] && str[*i])
		{
			*i += 1;
			j = -1;
			n = 1;
			*num = 1;
		}
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		n[3];

	split = malloc(8 * (ft_strlen(str) + 1));
	if (!split)
		return (NULL);
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	i = 0;
	split[n[1]] = malloc(ft_strlen(str));
	while (str[i])
	{
		if (ft_chech_charset(&i, str, charset, &n[2]) && n[0] != 0 && str[i])
		{
			split[n[1]++][n[0]] = '\0';
			n[0] = 0;
			split[n[1]] = malloc(ft_strlen(str));
		}
		else
			split[n[1]][n[0]++] = str[i++];
	}
	//split[n[1]][n[0]] = '\0';
	split[n[1] + 1] = NULL;
	return (split);
}
int main()
{
char** res;
for (res = ft_split("NOPENOPENOPE", "NOPE"); *res != 0; res++)
	printf("'%s',", *res);
printf("\n");
for (res = ft_split("", "NOPE"); *res != 0; res++)
	printf("'%s',", *res);
printf("\n");





}
