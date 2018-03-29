/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:44:19 by goarga            #+#    #+#             */
/*   Updated: 2015/09/16 18:41:27 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		f(int x)
{
	return (x);
}

int		*ft_map(int *tab, int lenght, int(*f)(int))
{
	int		i;
	int		*cola;

	cola = malloc(lenght * sizeof(int));
	i = 0;
	while (i < lenght)
	{
		cola[i] = f(tab[i]);
		i++;
	}
	return (cola);
}

int		main(void)
{
	int tab[5] = {1, 2, 3, 4, 5};
	int *zama;
	int i;

	i = 0;
	zama = ft_map(tab, 5, f);
	while (i < 5)
	{
		printf("%d", zama[i]);
		i++;
	}
	return (0);
}
