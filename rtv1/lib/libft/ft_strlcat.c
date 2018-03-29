/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:36:30 by goarga            #+#    #+#             */
/*   Updated: 2015/12/09 17:42:30 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_index;
	size_t	src_index;
	size_t	len;

	len = ft_strlen(dst);
	dst_index = 0;
	while (dst[dst_index])
		dst_index++;
	src_index = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	if (size == len)
		return (len + ft_strlen(src));
	else
	{
		while (src[src_index] && src_index < size - len - 1)
		{
			dst[dst_index] = src[src_index];
			dst_index++;
			src_index++;
		}
		dst[dst_index] = '\0';
		return (len + ft_strlen(src));
	}
}
