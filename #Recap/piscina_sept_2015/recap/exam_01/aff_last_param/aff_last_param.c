/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 15:29:34 by goarga            #+#    #+#             */
/*   Updated: 2015/09/22 15:42:46 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	char *str;

	str = argv[argc - 1];
	i = 0;
	if (argc > 1)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
