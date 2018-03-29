/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:48:21 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 17:55:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	int		src_size;

	i = 0;
	src_size = 0;
	while (src[i])
		src_size++;
	str = (char*)malloc(sizeof(src) * src_size);
	while (src_size != 0)
	{
		str[src_size] = src[src_size];
		src_size--;
	}
	return (str);
}
