/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 17:59:03 by goarga            #+#    #+#             */
/*   Updated: 2015/09/08 18:47:50 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int j;

	if (nb == 0)
		return (0);
	else
	{
		if (nb == 1)
			return (0);
		else
		{
			i = 1;
			j = 0;
			while (i <= nb)
			{
				if (nb % i == 0)
					j++;
				i++;
			}
			if (j == 2)
				return (1);
		}
	}
	return (0);
}
