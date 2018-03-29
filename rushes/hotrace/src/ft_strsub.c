/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:49:33 by goarga            #+#    #+#             */
/*   Updated: 2016/04/24 22:39:52 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*retur;
	char	*sretur;

	if (s == 0)
		return (NULL);
	retur = NULL;
	if (!(retur = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	sretur = retur;
	while (len != 0)
	{
		*retur = s[start];
		retur++;
		start++;
		len--;
	}
	*retur = '\0';
	return (sretur);
}
