/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 18:10:54 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 18:30:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				i++;
				j++;
			}
			else
				j++;
		}
		if (i == str_len(argv[1]))
			ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
