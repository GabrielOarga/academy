/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 18:19:35 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/20 20:51:50 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototipe.h"

long	max(long *v, int n)
{
	int		i;
	long	m;

	m = v[0];
	i = 1;
	while (i < n)
	{
		if (m < v[i])
			m = v[i];
		i++;
	}
	return (m);
}

void	parcurgere(long *x, long *v, char *s, long max)
{
	int i;

	i = 0;
	while (s[i])
		if (x[i] == max)
		{
			v[i] = operation(v[i], v[i + 1], s[i]);
			elimination(v, i + 1, ft_strlen(s) + 1);
			ft_strcpy(s + i, s + i + 1);
			elimination(x, i, ft_strlen(s));
		}
		else
			i++;
}

int		eval_expr(char *str)
{
	long	i;
	long	*v;
	long	*x;
	int		n;

	eliminare_spatii(str);
	v = vector_number(str);
	n = numar_numere(str);
	vector_operators(str);
	x = vector_incrementation(str);
	i = max(x, ft_strlen(str));
	while (i > 0)
	{
		parcurgere(x, v, str, i);
		i--;
	}
	return (v[0]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
