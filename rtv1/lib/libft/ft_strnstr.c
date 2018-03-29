/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:38:19 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 20:59:13 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*hit;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (*s1 != 0 && n > 0)
	{
		if (*s1 == *s2)
		{
			hit = s1;
			if (ft_strncmp(hit, s2, ft_strlen(s2)) == 0 && n >= ft_strlen(s2))
				return ((char*)hit);
		}
		s1++;
		n--;
	}
	return (NULL);
}
