/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 16:19:37 by goarga            #+#    #+#             */
/*   Updated: 2015/09/25 20:44:33 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		len(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (0);
	else
	{
		while (nbr)
		{
			nbr = nbr / 10;
			i++;
		}
		return (i - 1);
	}
}

char	*ft_itoa(int nbr)
{
	int		i;
	char	*v;
	int		j;

	i = len(nbr);
	j = i;
	v = NULL;
	v = (char *)malloc(sizeof(char) * len(nbr));
	if (nbr < 0)
	{
		nbr = nbr * -1;
		v[0] = '-';
		j++;
	}
	while (i >= 0)
	{
		v[j] = nbr % 10 + '0';
		nbr = nbr / 10;
		j--;
		i--;
	}
	return (v);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		printf("%s", ft_itoa(atoi(av[i])));
		i++;
	}
	return (0);
}
