/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 20:53:53 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/04 22:04:36 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

long	putere(long n)
{
	long p;

	p = 1;
	while (n != 0)
	{
		p = p * 10;
		n = n / 10;
	}
	p = p / 10;
	return (p);
}

void	ft_putnbr(int nb)
{
	long n;
	long p;

	n = nb;
	p = putere(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	while (n != 0)
	{
		ft_putchar(n / p + '0');
		n = n % p;
		p = p / 10;
	}
}
