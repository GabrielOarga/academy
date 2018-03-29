/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 17:37:24 by exam              #+#    #+#             */
/*   Updated: 2015/09/18 17:57:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	int				counterr;
	unsigned int	i;
	int				max;

	counterr = 1;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		max = tab[counterr];
		while (tab[counterr])
		{
			max = tab[counterr];
			if (tab[counterr] > max)
			{
				max = tab[counterr];
			}
				counterr++;
				i++;
		}
	}
	return (max);
}
