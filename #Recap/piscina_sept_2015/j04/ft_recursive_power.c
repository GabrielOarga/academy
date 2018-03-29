/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 09:19:42 by goarga            #+#    #+#             */
/*   Updated: 2015/09/08 09:44:39 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else
	{
		if (power == 0)
			return (1);
		else
		{
			if (power >= 1)
			{
				return (nb * ft_recursive_power(nb, power - 1));
			}
		}
	}
	return (0);
}
