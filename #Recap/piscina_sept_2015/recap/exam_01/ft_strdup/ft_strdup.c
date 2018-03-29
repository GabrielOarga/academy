/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 22:17:02 by goarga            #+#    #+#             */
/*   Updated: 2015/09/22 23:09:21 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	dest = (char*)malloc(sizeof(char) * ft_strlen(src));
	if (dest)
	{
		dest = src;
		return (dest);
	}
	else
		return (NULL);
}

int		main(int ac, char **av)
{
	char	*s;

	s = NULL;
	if (ac == 2)
	{
		s = av[1];
		printf("%s\n", ft_strdup(s));
	}
	else
		printf("cacat\n");
	return (0);
}
