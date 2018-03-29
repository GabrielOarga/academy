/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 19:20:40 by goarga            #+#    #+#             */
/*   Updated: 2015/09/24 23:10:20 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//a b c d e f g h i j k l m n o p q r s t u v w x y z

void	ft_putchar(char c)
{
	write (1, &c, 1);
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

int		alpha(char c)
{
	int		i;
	char	alpha;

	i = 0;
	alpha = 0;
	if (c >= 'a' && c <= 'z')
		alpha = 'a';
	else if (c >= 'A' && c <= 'Z')
		alpha = 'A';
	while (alpha != c)
	{
		i++;
		alpha++;
	}
	return (i);
}

char	*mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - alpha(str[i]);
		else if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - alpha(str[i]);
	   i++;	
	}
	return (str);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('\n');
	else
	{
		ft_putstr(mirror(av[1]));
	}
	return (0);
}
