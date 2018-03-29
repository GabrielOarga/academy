/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 19:05:24 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 19:22:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (argv[1][a] == argv[2][i])
				a++;
			i++;
		}
	}
	if (argv[1][a] == '\0')
		ft_putchar(49);
	else
		ft_putchar(48);
	ft_putchar('\n');
	return (0);
}
