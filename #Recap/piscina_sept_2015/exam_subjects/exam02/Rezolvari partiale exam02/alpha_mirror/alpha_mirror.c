/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 18:41:56 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 19:03:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int counter;

	counter = 0;
	if (argc == 2)
	{
		while (argv[1][counter])
		{
			if (argv[1][counter] <= 'z' && argv[1][counter] >= 'a')
			{
				argv[1][counter] = 'a' + ('z' - argv[1][counter]);
				ft_putchar(argv[1][counter]);
			}
			else if (argv[1][counter] <= 'Z' && argv[1][counter] >= 'A')
			{
				argv[1][counter] = 'A' + ('Z' - argv[1][counter]);
				ft_putchar(argv[1][counter]);
			}
			else
				ft_putchar(argv[1][counter]);
			counter++;
		}
	}
	ft_putchar('\n');
	return (0);
}
