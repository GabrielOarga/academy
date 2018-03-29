/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:50:14 by goarga            #+#    #+#             */
/*   Updated: 2015/12/13 18:41:39 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char			*retur;
	unsigned int	start;
	unsigned int	end;
	unsigned int	aux;

	if (s == 0)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	aux = 0;
	if (!(retur = (char*)malloc(sizeof(char) * end + 1)))
		return (NULL);
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	while (start <= end)
	{
		retur[aux++] = s[start++];
	}
	retur[aux] = '\0';
	return (retur);
}
