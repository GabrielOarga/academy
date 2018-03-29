/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablouri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:29:09 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/20 20:52:15 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototipe.h"

long	*vector_number(char *s)
{
	int		i;
	int		nr;
	long	*v;

	v = (long*)malloc(sizeof(v) * numar_numere(s));
	nr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			v[nr] = creare_numar_din_sir(s, i);
			if (v[nr] < 0)
				ft_strcpy(s + i - 1, s + i);
			while (s[i] >= '0' && s[i] <= '9' && s[i])
				i++;
			nr++;
		}
		else
			i++;
	}
	return (v);
}

void	vector_operators(char *s)
{
	int i;

	i = 0;
	while (s[i])
		if (!ft_strchr("+-/*()", s[i]))
			ft_strcpy(s + i, s + i + 1);
		else
			i++;
}

int		incrementation(char c, int k)
{
	if (c == '+' || c == '-')
		return (1 + k);
	else if (c == '*' || c == '/' || c == '%')
		return (2 + k);
	return (0);
}

long	*vector_incrementation(char *s)
{
	long	*v;
	int		nr;
	int		i;
	int		k;

	v = (long*)malloc(sizeof(long) * ft_strlen(s));
	nr = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '(')
		{
			ft_strcpy(s + i, s + i + 1);
			k = k + 2;
		}
		if (s[i] == ')')
		{
			k = k - 2;
			ft_strcpy(s + i, s + i + 1);
		}
		v[nr++] = incrementation(s[i], k);
		i++;
	}
	return (v);
}

void	elimination(long *v, int poz, int n)
{
	poz++;
	while (poz <= n)
	{
		v[poz - 1] = v[poz];
		poz++;
	}
}
