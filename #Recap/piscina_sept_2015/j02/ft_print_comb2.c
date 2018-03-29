/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:27:44 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/04 20:12:19 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	afis(int c)
{
	ft_putchar(c / 10 + 48);
	ft_putchar(c % 10 + 48);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			afis(a);
			ft_putchar(' ');
			afis(b);
			if (a != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}
