/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 01:24:05 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 02:03:42 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	maj(char s[])
{
	int i;

	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 1;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putchar(char s1)
{
	write(1, &s1, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		maj(argv[i]);
		if (!ft_strcmp(argv[i], "PRESIDENT") || !ft_strcmp(argv[i], "ATTACK"))
		{
			i = argc - 1;
			write(1, "Alert!!!", 8);
			ft_putchar('\n');
		}
		if (!ft_strcmp(argv[i], "POWERS"))
		{
			i = argc - 1;
			write(1, "Alert!!!", 8);
			ft_putchar('\n');
		}
		i++;
	}
return (0);
}
