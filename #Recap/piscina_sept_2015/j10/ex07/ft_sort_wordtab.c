/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 22:15:58 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/15 22:51:07 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_wordtab(char **tab)
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
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
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
