/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 08:52:01 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/20 21:08:07 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototipe.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *source)
{
	int i;

	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	int		i;
	int		x[30];

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = -1;
	x[++i] = n % 10;
	n = n / 10;
	while (n)
	{
		x[++i] = n % 10;
		n = n / 10;
	}
	while (i >= 0)
	{
		ft_putchar(x[i] + '0');
		i--;
	}
}

int		ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		else
			i++;
	}
	return (0);
}
