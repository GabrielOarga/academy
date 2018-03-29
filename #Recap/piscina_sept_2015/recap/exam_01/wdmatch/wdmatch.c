/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 01:49:44 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 02:44:51 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		wdmatch(char *str, char *match)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == match[j])
			j++;
		i++;
	}
	if (ft_strlen(match) == j)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[2], av[1]))
		{
			ft_putstr(av[1]);
			ft_putchar('\n');
		}
		else
			ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
