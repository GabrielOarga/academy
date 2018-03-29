/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 20:42:53 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 22:10:37 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int nbr)
{
	int i;

	i = 2;
	if (nbr == 1)
		printf("1");
	else
		while (nbr != 1)
		{
			while (nbr % i == 0)
			{
				nbr = nbr / i;
				printf("%d", i);
				if (nbr != 1)
					printf("*");
			}
			i++;
		}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("\n");
	else
	{
		fprime(atoi(av[1]));
	}
	return (0);
}
	