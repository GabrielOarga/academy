/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:44:31 by goarga            #+#    #+#             */
/*   Updated: 2015/09/22 19:16:54 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(str) - 1;
	aux = 0;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}

int		main(int ac, char **av)
{
	int i;
	char *s;

	i = 0;
	s = NULL;
	s = (char *)malloc((ft_strlen(av[1]) * sizeof(char)) + 1);
	if (s)
	{
		s = av[1];
		ft_strrev(s);
		if (ac != 2)
			printf("Introduceti un parametru");
		else
			printf("%s", s);
	}
	return (0);
}
