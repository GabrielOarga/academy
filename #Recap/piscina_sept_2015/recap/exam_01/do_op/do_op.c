/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:36:52 by goarga            #+#    #+#             */
/*   Updated: 2015/09/24 19:16:46 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	do_op(int x, char op, int y)
{
	int rez;

	rez = 0;
	if (op == '+')
		rez = x + y;
	else if (op == '-')
		rez = x - y;
	else if (op == '*')
		rez = x * y;
	else if (op == '/')
		rez = x / y;
	else if (op == '%')
		rez = x % y;
	printf("%d", rez);
}

int		main(int ac, char **av)
{
	int		*x;
	int		*y;

	if (ac != 4)
		ft_putchar('\n');
	else
	{
		x = (int *)malloc(sizeof(int));
		y = (int *)malloc(sizeof(int));
		*x = atoi(av[1]);
		*y = atoi(av[3]);
		do_op(*x, *av[2], *y);
	}
	return (0);
}
