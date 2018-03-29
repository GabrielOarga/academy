/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:48:06 by goarga            #+#    #+#             */
/*   Updated: 2015/12/14 17:53:43 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*retur;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	retur = ft_strnew(ft_strlen(s));
	if (retur == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		retur[index] = f(index, s[index]);
		index++;
	}
	return (retur);
}
