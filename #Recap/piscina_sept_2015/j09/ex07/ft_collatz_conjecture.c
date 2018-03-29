/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 01:02:49 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 02:04:22 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (1);
	if (base % 2 == 0)
		base = base / 2;
	else
		base = base * 3 + 1;
	return (1 + ft_collatz_conjecture(base));
}
