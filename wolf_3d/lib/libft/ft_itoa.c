/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:38:41 by goarga            #+#    #+#             */
/*   Updated: 2015/11/08 12:02:06 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	ft_size(long nbr)
{
	int		index;

	index = 0;
	if (nbr == 0)
		index++;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		index++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		index++;
	}
	return (index);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		size;

	nbr = n;
	size = ft_size(nbr) - 1;
	str = NULL;
	str = (char*)malloc(sizeof(char) * ft_size(nbr) + 1);
	if (str == NULL)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	str[ft_size(n)] = '\0';
	return (str);
}
