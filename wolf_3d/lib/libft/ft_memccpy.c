/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 22:55:26 by goarga            #+#    #+#             */
/*   Updated: 2016/01/13 20:47:43 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ssrc;
	char	*sdst;

	ssrc = (char*)src;
	sdst = (char*)dst;
	while (n > 0 && *ssrc != c)
	{
		n--;
		*sdst++ = *ssrc++;
	}
	if (n > 0)
	{
		*sdst++ = *ssrc++;
		return ((void*)sdst);
	}
	else
		return (NULL);
}
