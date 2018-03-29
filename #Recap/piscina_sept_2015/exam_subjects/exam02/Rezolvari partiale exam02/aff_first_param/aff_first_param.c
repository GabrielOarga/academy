/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 17:05:36 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 17:11:38 by exam             ###   ########.fr       */
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
	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (argv[1][counter] != '\0')
	{
		ft_putchar(argv[1][counter]);
		counter++;
	}
	ft_putchar('\n');
	return (0);
}
