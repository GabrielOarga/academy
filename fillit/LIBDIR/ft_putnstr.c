/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 23:12:58 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:48:55 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	size_t index;

	index = 0;
	while (s[index] != '\0' && index < n)
	{
		ft_putchar(s[index]);
		index++;
	}
}
