/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:33:05 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 15:37:53 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *v;

	i = 0;
	v = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		v[i] = min;
		min++;
		i++;
	}
	*range = v;
	return (i);
}
