/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 21:38:37 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/16 18:50:45 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

int		digit_count(int n)
{
	int k;

	k = 0;
	while (n != 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}

int		pow_ten(int n)
{
	int k;
	int i;
	int p;

	p = 1;
	k = digit_count(n);
	i = 0;
	while (i < k - 1)
	{
		p *= 10;
		i++;
	}
	return (p);
}

void	ft_putnbr(int nb)
{
	int		k;
	long	nb1;

	nb1 = nb;
	k = pow_ten(nb1);
	if (nb1 < 0)
	{
		nb1 = ~(nb1) + 1;
		ft_putchar('-');
	}
	while (k != 0)
	{
		ft_putchar('0' + nb1 / k % 10);
		k = k / 10;
	}
}
