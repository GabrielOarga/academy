/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:48:11 by goarga            #+#    #+#             */
/*   Updated: 2016/01/13 23:23:54 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int		ft_strlen(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
		i++;
	return(i);
}

void	ft_strrev(char *buff)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(buff) - 1;
	while (i < j)
	{
		aux = buff[i];
		buff[i] = buff [j];
		buff[j] = aux;
		i++;
		j--;
	}
}

char	*ft_itoa_base(int val, int base)
{
	char	*buff;
	char	*begin_buff;
	int		sign;
	long	result;

	result = val;
	sign = 1;
	buff  = NULL;
	buff = (char *)malloc(sizeof(char) * 32);
	begin_buff = buff;
	if (val == 0)
	{
		*buff = '0';
		buff++;
		*buff = '\0';
		return (begin_buff);
	}
	if (result < 0 && base == 10)
	{
		sign = -1;
		result = result * (-1);
	}
	else if (result < 0)
		result = result * (-1);
	while (result > 0)
	{
		*buff = "0123456789ABCDEF"[result % base];
		result = result / base;
		buff++;
	}
	if (sign < 0)
	{
		*buff = '-';
		buff++;
	}
	*buff = '\0';
	buff = begin_buff;
	ft_strrev(buff);
	return (buff);
}

int		main(void)
{
	int		val = 123752735;
	int		base = 16;

	printf("%s\n", ft_itoa_base(val, base));
	return (0);
}
