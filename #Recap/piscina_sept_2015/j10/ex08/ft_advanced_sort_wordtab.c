/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 22:15:58 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/15 22:57:56 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		ok;
	int		i;
	char	*s;

	ok = 0;
	while (!ok)
	{
		ok = 1;
		i = 1;
		while (tab[i] != 0)
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				s = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = s;
				ok = 0;
			}
			i++;
		}
	}
}
