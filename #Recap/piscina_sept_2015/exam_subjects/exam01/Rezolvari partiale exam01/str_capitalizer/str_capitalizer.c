/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 18:10:43 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 20:01:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		bbq(char c)
{
	if (c == ' ' || c == '\t')
		return (3);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else
		return (0);
}

char	*ft_cap(int i, char *c)
{
	while (c[i])
	{
		if (bbq(c[i]) == 3)
			i++;
		else if (bbq(c[i]) == 0)
			i++;
		else if (i == 0 && bbq(c[i]) == 1)
		{
			c[i] = c[i] - 32;
			i++;
		}
		else if (bbq(c[i - 1]) == 3 && bbq(c[i]) == 1)
		{
			c[i] = c[i] - 32;
			i++;
		}
		else if (i != 0 && bbq(c[i - 1]) != 3 && bbq(c[i]) == 2)
		{
			c[i] = c[i] + 32;
			i++;
		}
		else
			i++;
	}
	return (c);
}

int		main(int argc, char **argv)
{
	int x;

	x = 1;
	if (argc == 1)
		ft_putchar('\n');
	while (x < argc)
	{
		ft_putstr(ft_cap(0, argv[;
		x++;
	}
	return (0);
}
