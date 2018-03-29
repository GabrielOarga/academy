/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 20:31:26 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 23:31:49 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	cmmdc(int x, int y)
{
	int aux;

	aux = 0;
	while (y)
	{
		aux = x % y;
		x = y;
		y = aux;
	}
	printf("%d\n", x);
}

int		main(int ac, char **av)
{
	int	*x;
	int *y;
	int	i;

	i = 1;
	if (ac != 3)
		printf("\n");
	else
	{
		x = (int*)malloc(sizeof(int));
		y = (int*)malloc(sizeof(int));
		*x = atoi(av[1]);
		*y = atoi(av[2]);
		cmmdc(*x, *y);
	}
	return (0);
}
