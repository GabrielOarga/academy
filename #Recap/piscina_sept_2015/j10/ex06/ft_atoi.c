/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:11:48 by exam              #+#    #+#             */
/*   Updated: 2015/09/15 21:55:33 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspc(char a, int b)
{
	if (((a >= 9 && a <= 13) || a == ' ') && b == 0)
		return (1);
	else
		return (0);
}

int		ft_minus_i(char a, int b)
{
	if (a == '-' && b == 0)
		return (1);
	else if (a == '+' && b == 0)
		return (2);
	else
		return (0);
}

int		ft_valid(char a, int x, int y)
{
	if (a != '\0')
	{
		if (((a >= '0' && a <= '9') || ft_isspc(a, x) || ft_minus_i(a, y)))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	ft_ch_nb(char z, int *nr, int *a)
{
	if (z != ' ' && !(z >= 9 && z <= 13) && z != '-' && z != '+')
	{
		*nr = *nr * 10 + (z - '0');
		a[0] = 1;
		a[1] = 1;
	}
	else if (z == '-')
	{
		a[2] = 1;
		a[4]++;
		a[0] = 1;
	}
	else if (z == '+')
	{
		a[3] = 1;
		a[4]++;
		a[0] = 1;
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int nr;
	int a[5];

	i = 0;
	a[0] = 0;
	a[4] = 0;
	nr = 0;
	a[1] = 0;
	while (ft_valid(str[i], a[0], a[1]) == 1)
	{
		if (a[4] <= 1)
			ft_ch_nb(str[i], &nr, a);
		else
			nr = 0;
		i++;
	}
	if (a[2] == 1)
	{
		nr = nr * -1;
	}
	return (nr);
}
