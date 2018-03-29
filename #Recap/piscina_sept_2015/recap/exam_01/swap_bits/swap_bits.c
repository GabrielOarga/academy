/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 23:13:22 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 12:00:28 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
	unsigned char i;
	unsigned char j;
	unsigned char n;
	unsigned char rez;
	unsigned char x;

	i = 0;
	j = 4;
	n = 4;
	rez = 0;
	x = 0;
	x = ((octet >> i) ^ (octet >> j)) & ((1U << n) - 1);
	rez = octet ^ ((x << i) | (x << j));
	return (rez);
}

int		main(void)
{
	printf("%d", swap_bits(30));
	return (0);
}
