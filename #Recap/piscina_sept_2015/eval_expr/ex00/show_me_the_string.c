/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_u_no_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 10:17:34 by goarga            #+#    #+#             */
/*   Updated: 2015/09/20 22:09:25 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"

extern char	*g_string;

int		size(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

void	valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g_string = (char*)malloc(sizeof(char) * size(str));
	while (str[i] != '\0')
	{
		if ((str[i] >= '9' && str[i] <= '13') || (str[i] == ' '))
			i++;
		else
		{
			g_string[j] = str[i];
			j++;
			i++;
		}
		g_string[j] = '\0';
	}
}
