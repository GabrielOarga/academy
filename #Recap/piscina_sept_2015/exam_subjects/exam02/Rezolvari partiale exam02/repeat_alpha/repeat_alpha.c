/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 17:14:55 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 17:32:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		verif(int argc)
{
	if (argc != 2)
	{
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int counter;
	int result;

	counter = 0;
	if (verif(argc) == 1)
	{
		while (argv[1][counter])
		{
			if (argv[1][counter] >= 'a' && argv[1][counter] <= 'z')
				result = argv[1][counter] - 96;
			else if (argv[1][counter] >= 'A' && argv[1][counter] <= 'Z')
				result = argv[1][counter] - 64;
			else
				ft_putchar(argv[1][counter]);
			while (result != 0)
			{
				ft_putchar(argv[1][counter]);
				result--;
			}
			counter++;
		}
	}
	ft_putchar('\n');
	return (0);
}
