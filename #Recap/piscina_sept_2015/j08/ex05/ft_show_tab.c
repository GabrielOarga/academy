/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spelea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 19:51:13 by spelea            #+#    #+#             */
/*   Updated: 2015/09/15 23:03:10 by spelea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putchar(char c);

int		ten(int n)
{
	int i;
	int j;
	int k;

	j = 0;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	k = 1;
	i = 0;
	while (i < j - 1)
	{
		k = k * 10;
		i++;
	}
	return (k);
}

void	ft_putnbr(int n)
{
	int		i;
	long	x;

	x = n;
	i = ten(x);
	if (x < 0)
	{
		x = ~(x) + 1;
		ft_putchar('-');
	}
	while (i != 0)
	{
		ft_putchar('0' + x / i % 10);
		x = x / 10;
	}
}

void	tipar(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			ft_putchar(s[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].str != '\0')
		{
			ft_putchar(par[i].str[j]);
			j++;
		}
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		tipar(par[i].tab);
		i++;
	}
}
