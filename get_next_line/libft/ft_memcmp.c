/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:34:54 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 22:48:08 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
			i++;
		else
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
	}
	return (0);
}
