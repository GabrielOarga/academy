/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 17:14:05 by goarga            #+#    #+#             */
/*   Updated: 2015/09/24 17:44:29 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int * tab, unsigned int len)
{
	int	i;
	int	max;

	i = 0;
	if (len)
	{
		while (i < len)
		{
			if (i == 0)
				max = tab[i];
			else
				if (tab[i] > max)
					max = tab[i];
			i++;
		}
		return (max);
	}
	else
		return (0);
}

int		main(void)
{
	int tab[10] = {12,1124,0,-1346724,2};
	printf("%d", max(tab, 5));
	return (0);
}
