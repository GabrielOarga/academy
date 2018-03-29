/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 18:27:35 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 19:03:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		numar(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		rast(int n)
{
	int r;

	r = 0;
	while (n != 0)
	{
		r = r * 10 + n % 10;
		n /= 10;
	}
	return (r);
}

char	*ft_itoa(int nbr)
{
	int		n;
	int		i;
	int		pas;
	char	*s;

	n = rast(nbr);
	s = malloc(sizeof(*s) * (numar(n) + 1));
	pas = numar(n);
	i = 0;
	while (i < pas)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	s[pas] = '\0';
	return (s);
}
