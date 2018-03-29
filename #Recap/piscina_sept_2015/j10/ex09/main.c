/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 19:21:05 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/16 21:53:46 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

int		main(int argc, char **argv)
{
	int		(*f[5])(int, int);
	int		(*g)(int, int);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (argc == 4)
	{
		if (ft_op(argv[2]) == -1)
		{
			ft_usage(0, 0);
			return (0);
		}
		g = f[ft_op(argv[2])];
		ft_putnbr(g(ft_atoi(argv[1]), ft_atoi(argv[3])));
		return (0);
	}
	write(1, "0", 1);
	return (0);
}
