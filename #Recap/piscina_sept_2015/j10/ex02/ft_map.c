/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:19:23 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/15 16:59:19 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *a;

	i = 0;
	a = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		a[i] = f(tab[i]);
		i++;
	}
	return (a);
}
