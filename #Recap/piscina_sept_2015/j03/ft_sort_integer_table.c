/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 23:29:15 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/05 23:41:28 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int ok;
	int aux;
	int i;

	ok = 0;
	i = 0;
	while (ok == 0)
	{
		ok = 1;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ok = 0;
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
			}
			i++;
		}
	}
}
