/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 23:24:16 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 00:00:09 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	carac(char c)
{
	int i;

	i = 0;
	while (i < 42)
	{
		if (c == 'Z')
			c = 'A';
		else if (c == 'z')
			c = 'a';
		else
			c++;
		i++;
	}
	return (c);
}

char	transf(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (carac(c));
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = transf(str[i]);
		i++;
	}
	return (str);
}
