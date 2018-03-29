/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 18:12:59 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 19:22:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (s[j + 1])
		j++;
	while (i <= j / 2)
	{
		c = s[i];
		s[i] = s[j - i];
		s[j - i] = c;
		i++;
	}
	return (s);
}

int		numar(int n)
{
	int	i;

	if (n < 0)
		n = -n;
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*s;
	int		ok;
	int		i;

	s = malloc(sizeof(*s) * numar(nbr) + 2);
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ok = 0;
	}
	else
		ok = 1;
	s[i++] = nbr % 10 + '0';
	nbr = nbr / 10;
	while (nbr)
	{
		s[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (ok == 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
