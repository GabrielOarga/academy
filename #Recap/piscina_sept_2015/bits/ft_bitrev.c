/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 15:18:34 by goarga            #+#    #+#             */
/*   Updated: 2015/09/18 16:13:51 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	bit(unsigned char octet)
{
	unsigned char	t;
	int 			i;
	
	t = 0;
	i = 0;
	while (i < 8)
	{
		t  = octet % 2 + (t << 1);
		octet = octet / 2;
		i++;
	}
	return (t);
}

int				main(void)
{
	printf("%d", bit(34));
	return (0);
}
