/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 02:57:14 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 04:02:59 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		valid(char c)
{
	if (c >= 0 && c <= 31)
		return (2);
	else if (c == 32)
		return (1);
	else
		return (0);
}

void	epur_str(char *str, int i, int ok)
{
	while (str[i])
	{
		if (valid(str[i]) == 0)
		{
			ft_putchar(str[i]);
			ok = 1;
		}
		else if (valid(str[i]) == 2 && valid(str[i + 1]) == 0 && ok != 0)
		{
			ft_putchar(str[i]);
			ok = 1;
		}
		else if (valid(str[i]) == 1 && valid(str[i + 1]) == 0 && ok != 0)
		{
			ft_putchar(str[i]);
			ok = 1;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('\n');
	else
	{
		epur_str(av[1], 0, 0);
		ft_putchar('\n');
	}
	return (0);
}
