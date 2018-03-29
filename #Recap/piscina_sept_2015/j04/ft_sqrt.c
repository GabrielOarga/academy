/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:45:52 by goarga            #+#    #+#             */
/*   Updated: 2015/09/08 17:52:56 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	if (nb == 0)
		return (0);
	else
	{
		i = 1;
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			else
				i++;
		}
	}
	return (0);
}