/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 18:52:55 by goarga            #+#    #+#             */
/*   Updated: 2015/09/23 19:50:29 by goarga           ###   ########.fr       */
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
}

int		valid(char c)
{
	if (c >= 0 && c <= 32)
		return(1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= 'A' && c <= 'Z')
		return (3);
	return (0);

}

char	*cap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (valid(str[i - 1]) == 1 && valid(str[i]) == 2)
			str[i] = str[i] - 32;
		else if (valid(str[i - 1]) != 1 && valid(str[i]) == 3)
			str[i] = str[i] + 32;
		else if (valid(str[i]) == 2 && i == 0)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		ft_putchar('\n');
	else
		while (av[i])
		{
			ft_putstr(cap(av[i]));
			ft_putchar('\n');
			i++;
		}
	return (0);
}
