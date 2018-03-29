/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:49:51 by goarga            #+#    #+#             */
/*   Updated: 2016/04/24 22:39:21 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retur;
	char	*sretur;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	retur = NULL;
	if (!(retur = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	sretur = retur;
	while (*s1)
	{
		*retur = *s1;
		retur++;
		s1++;
	}
	while (*s2)
	{
		*retur = *s2;
		retur++;
		s2++;
	}
	*retur = '\0';
	return (sretur);
}
