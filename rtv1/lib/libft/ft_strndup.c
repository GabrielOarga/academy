/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:00:50 by goarga            #+#    #+#             */
/*   Updated: 2015/12/13 20:08:07 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = NULL;
	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] && n > 0)
	{
		s2[i] = s1[i];
		i++;
		n--;
	}
	s2[i] = '\0';
	return (s2);
}
