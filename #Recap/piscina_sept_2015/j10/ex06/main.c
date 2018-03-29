/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 19:59:48 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/16 21:56:48 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hads.h"

int		ft_valid_op(char *c)
{
	if (ft_strlen(c) == 1 && (c[0] == '+' || c[0] == '-' ||
				c[0] == '%' || c[0] == '/' || c[0] == '*'))
		return (1);
	else
		return (0);
}

int		ft_op(char o)
{
	if (o == '+')
		return (0);
	else if (o == '-')
		return (1);
	else if (o == '*')
		return (2);
	else if (o == '/')
		return (3);
	else if (o == '%')
		return (4);
	else
		return (-1);
}

int		ft_valid_calc(char o, int y)
{
	if (o == '/' && y == 0)
		return (0);
	if (o == '%' && y == 0)
		return (0);
	return (1);
}

void	init(long (*f[5])(int, int))
{
	f[0] = &ft_add;
	f[1] = &ft_minus;
	f[2] = &ft_multiply;
	f[3] = &ft_divide;
	f[4] = &ft_modulo;
}

int		main(int ac, char **av)
{
	char	o;
	long	(*f[5])(int, int);
	long	(*g)(int, int);

	init(f);
	if (ac == 4 && ft_valid_op(av[2]))
	{
		o = av[2][0];
		if (ft_valid_calc(o, ft_atoi(av[3])))
		{
			g = f[ft_op(o)];
			ft_putnbr(g(ft_atoi(av[1]), ft_atoi(av[3])));
			ft_putchar('\n');
		}
		else if (o == '/')
			write(1, "Stop : division by zero\n", 24);
		else if (o == '%')
			write(1, "Stop : modulo by zero\n", 22);
	}
	else if (!ft_valid_op(av[2]) && ac == 4)
		write(1, "0", 1);
	return (0);
}
