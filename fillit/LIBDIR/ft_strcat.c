/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:35:15 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 22:53:40 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*start;

	start = s1;
	while (*s1)
		s1++;
	while (*s2)
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = 0;
	return (start);
}
