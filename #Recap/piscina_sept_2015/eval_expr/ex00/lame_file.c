/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_the_money.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 09:47:09 by goarga            #+#    #+#             */
/*   Updated: 2015/09/20 15:47:20 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
