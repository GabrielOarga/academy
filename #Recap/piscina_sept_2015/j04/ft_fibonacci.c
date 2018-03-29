/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:05:47 by goarga            #+#    #+#             */
/*   Updated: 2015/09/08 22:59:42 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else
	{
		if (index == 0)
			return (0);
		else
		{
			if (index == 1)
				return (1);
			else
				return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
		}
		return (0);
	}
}
