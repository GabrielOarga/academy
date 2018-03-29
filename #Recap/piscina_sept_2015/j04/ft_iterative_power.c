/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 15:59:54 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/07 16:21:31 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int p;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	p = nb;
	while (power > 1)
	{
		nb = nb * p;
		power--;
	}
	return (nb);
}
