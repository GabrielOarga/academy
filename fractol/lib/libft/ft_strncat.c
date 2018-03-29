/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:35:43 by goarga            #+#    #+#             */
/*   Updated: 2015/11/16 17:35:44 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*start;

	start = s1;
	while (*s1)
		s1++;
	while (*s2 && (n > 0))
	{
		*s1 = *s2;
		s2++;
		s1++;
		n--;
	}
	*s1 = 0;
	return (start);
}