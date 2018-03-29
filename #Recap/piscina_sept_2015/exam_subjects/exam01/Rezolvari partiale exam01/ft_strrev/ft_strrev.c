/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:40:15 by exam              #+#    #+#             */
/*   Updated: 2015/09/11 17:45:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	aux = str;
	j = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		aux[j] = str[i];
		j++;
		i--;
	}
	return (aux);
}
