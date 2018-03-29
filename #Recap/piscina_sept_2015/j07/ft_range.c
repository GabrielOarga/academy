/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 13:52:19 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 15:00:22 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *v;

	i = 0;
	if (min > max)
		return (0);
	v = (int *)malloc(sizeof(*v) * (max - min));
	while (min < max)
	{
		v[i] = min;
		i++;
		min++;
	}
	return (v);
}
