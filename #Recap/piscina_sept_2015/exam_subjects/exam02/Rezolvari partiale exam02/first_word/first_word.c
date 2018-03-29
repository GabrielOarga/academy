/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 17:12:00 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 17:34:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	afisare(char *s, int i, int j)
{
	while (i < j)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 2)
		ft_putchar('\n');
	else
	{
		i = 0;
		while ((argv[1][i] == '	' || argv[1][i] == ' ') && argv[1][i] != '\0')
			i++;
		j = i;
		while (argv[1][j] != '	' && argv[1][j] != ' ' && argv[1][j] != '\0')
			j++;
		if (argv[1][i])
			afisare(argv[1], i, j);
		ft_putchar('\n');
	}
	return (0);
}
