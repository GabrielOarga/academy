/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:04:28 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 17:14:53 by exam             ###   ########.fr       */
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

	i = 0;
	if (argc == 1)
		return (0);
	else
		while (argv[argc - 1][i])
		{
			ft_putchar(argv[argc - 1][i]);
			i++;
		}
	ft_putchar('\n');
	return (0);
}
