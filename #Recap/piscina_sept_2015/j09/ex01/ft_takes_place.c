/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:52:46 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/10 18:53:37 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int i;

	i = hour;
	if (hour > 12)
		i = i - 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 23)
		printf("11.00 P.M. AND 12.00 A.M.\n");
	else if (hour == 11)
		printf("11.00 A.M. AND 12.00 P.M.\n");
	else if (hour == 24 || hour == 0)
		printf("12.00 A.M. AND 1.00 A.M.\n");
	else if (hour < 11)
		printf("%d.00 A.M. AND %d.00 A.M.\n", i, i + 1);
	else
		printf("%d.00 P.M AND %d.00 P.M.\n", i, (i + 1) % 12);
}
