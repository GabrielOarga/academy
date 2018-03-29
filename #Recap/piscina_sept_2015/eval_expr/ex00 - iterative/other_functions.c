/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 10:09:02 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/20 20:53:12 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototipe.h"

void	eliminare_spatii(char *s)
{
	int i;

	i = 0;
	while (s[i])
		if ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
			ft_strcpy(s + i, s + i + 1);
		else
			i++;
}

int		numar_numere(char *s)
{
	int nr;
	int i;

	i = 0;
	nr = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9' && s[i])
				i++;
			nr++;
		}
		else
			i++;
	}
	return (nr);
}

int		is_pos(char *s, int i)
{
	if (s[i] == '-' && (s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '*'
				|| s[i - 1] == '/' || s[i - 1] == '(' || s[i - 1] == '%'))
		return (-1);
	else if (s[i] == '-' && i == 0)
		return (-1);
	else
		return (1);
}

long	creare_numar_din_sir(char *s, int i)
{
	long		n;
	int			j;

	n = 0;
	if (is_pos(s, i - 1) == -1)
		j = -1;
	else
		j = 1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	n = n * j;
	return (n);
}

long	operation(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	return (a / b);
}
