/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 19:31:28 by goarga            #+#    #+#             */
/*   Updated: 2015/11/16 18:40:47 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = NULL;
	if (!(ptr = (void*)malloc(size)))
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}
