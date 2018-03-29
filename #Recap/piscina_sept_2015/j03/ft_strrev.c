/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 22:06:15 by goarga            #+#    #+#             */
/*   Updated: 2015/09/05 23:31:49 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count(char *str)
{
	int k;

	k = 0;
	while (str[k] != '\0')
	{
		k++;
	}
	return (k);
}

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int aux;

	i = 0;
	j = count(str) - 1;
	while (i <= j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}
