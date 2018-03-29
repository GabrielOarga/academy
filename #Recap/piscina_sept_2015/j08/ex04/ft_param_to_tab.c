/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:58:05 by goarga            #+#    #+#             */
/*   Updated: 2015/09/15 19:51:17 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				**ft_split_whitespaces(char *str);

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char				*ft_strdup(char *str)
{
	char		*dest;
	int			i;

	i = 0;
	dest = (char*)malloc(sizeof(*dest) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*dest;
	int				i;

	i = 0;
	dest = (t_stock_par*)malloc(sizeof(*dest) * (ac + 1));
	while (i < ac)
	{
		dest[i].size_param = ft_strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = ft_strdup(av[i]);
		dest[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	dest[i].str = 0;
	return (dest);
}
