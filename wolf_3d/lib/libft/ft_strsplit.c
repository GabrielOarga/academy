/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:50:32 by goarga            #+#    #+#             */
/*   Updated: 2016/02/21 15:16:17 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int		ft_ntab(const char *s, char c)
{
	int		ntab;

	ntab = 0;
	while (*s)
	{
		if (*s != c)
		{
			ntab++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (ntab);
}

static int		ft_count(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		**stab;

	if (s == 0 || c == 0)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) * (ft_ntab(s, c) + 1))))
		return (NULL);
	stab = tab;
	while (*s)
	{
		if (*s != c)
		{
			*tab = ft_strndup(s, (size_t)ft_count(s, c));
			tab++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	*tab = NULL;
	return (stab);
}
