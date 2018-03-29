/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:59:56 by goarga            #+#    #+#             */
/*   Updated: 2015/09/15 18:29:48 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *str)
{
	int		size;
	char	*dest;
	int		i;

	size = 0;
	i = 0;
	while (str[size])
	{
		size++;
	}
	dest = (char*)malloc(sizeof(*dest) * size + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

