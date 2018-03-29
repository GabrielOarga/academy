/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:39:11 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 20:54:15 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != 0 || *s2 != 0) && n > 0)
	{
		if (*(unsigned char*)s1 == *(unsigned char*)s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
	}
	return (0);
}
