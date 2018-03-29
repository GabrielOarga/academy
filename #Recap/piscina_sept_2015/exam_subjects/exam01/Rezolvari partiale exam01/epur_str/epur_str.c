/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:41:18 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 18:22:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	constr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		if (i == 0 && (s[i] == '	' || s[i] == ' '))
			ft_strcpy(s + i, s + i + 1);
		else if (s[i] == ' ' && (s[i + 1] == '	' || s[i + 1] == ' '))
			ft_strcpy(s + i + 1, s + i + 2);
		else
			i++;
	i--;
	while (s[i] == '	' || s[i] == ' ')
	{
		s[i] = '\0';
		i--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		ft_putchar('\n');
	else
	{
		constr(argv[1]);
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}
