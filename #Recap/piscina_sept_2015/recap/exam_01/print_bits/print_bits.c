/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 13:06:14 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 14:03:29 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_bit(unsigned char octet)
{
	int				i;
	unsigned char	rev;

	i = 0;
	rev = 0;
	while (i < 8)
	{
		rev = octet % 2 + (rev * 2);
		octet = octet / 2;
		i++;
	}
	while (i > 0)
	{
		if (rev % 2 == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
		rev = rev / 2;
		i--;
	}
}

int		main(void)
{
	print_bit(2);
}
