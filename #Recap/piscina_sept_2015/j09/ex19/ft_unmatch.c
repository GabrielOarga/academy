/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 13:09:37 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 13:21:44 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int lenght)
{
	int i;
	int j;
	int n;

	i = 0;
	while (i < lenght)
	{
		j = 0;
		n = 0;
		while (j < lenght)
		{
			if (tab[j] == tab[i])
				n++;
			j++;
		}
		if (n % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
