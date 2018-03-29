/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:47:48 by goarga            #+#    #+#             */
/*   Updated: 2015/12/14 17:52:34 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*retur;
	char	*start;

	if (s == 0 || f == 0)
		return (NULL);
	retur = NULL;
	if (!(retur = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	start = retur;
	while (*s)
	{
		*retur = f(*s);
		retur++;
		s++;
	}
	return (start);
}
