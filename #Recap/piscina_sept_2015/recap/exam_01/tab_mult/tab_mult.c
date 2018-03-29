/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 14:10:07 by goarga            #+#    #+#             */
/*   Updated: 2015/09/24 02:02:09 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int x)
{
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	ft_putchar(x % 10 + '0');
}

int		badatoi(char *s)
{
	long nbr;
	int i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	return (nbr);
}

void	calc(int nb, int i)
{
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		ft_putnbr(nb);
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		ft_putnbr(i * nb);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		ft_putchar('\n');
	else
	{
		while (i < ac)
		{
			calc(badatoi(av[1]), 1);
			i++;
		}
	}
	return (0);
}
