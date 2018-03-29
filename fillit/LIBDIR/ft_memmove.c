/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:34:17 by goarga            #+#    #+#             */
/*   Updated: 2015/11/16 17:34:47 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*aux;

	aux = NULL;
	if (!(aux = (void*)malloc(len)))
		return (NULL);
	ft_memcpy(aux, src, len);
	ft_memcpy(dst, aux, len);
	return (dst);
}
