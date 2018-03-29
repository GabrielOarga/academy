/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:41:30 by goarga            #+#    #+#             */
/*   Updated: 2015/12/08 22:27:44 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			nb;
	int			neg;

	neg = 1;
	nb = 0;
	while (*str >= 0 && *str <= 32)
		str++;
	if (*str == '+' && ft_isdigit(*(str + 1)) == 1)
		str++;
	if (*str == '-' && ft_isdigit(*(str + 1)) == 1)
	{
		neg = neg * (-1);
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * neg);
}
