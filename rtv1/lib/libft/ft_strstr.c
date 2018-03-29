/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:37:48 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 20:57:33 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*hit;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			hit = s1;
			if (ft_strncmp(hit, s2, ft_strlen(s2)) == 0)
				return ((char*)hit);
		}
		s1++;
	}
	return (NULL);
}
