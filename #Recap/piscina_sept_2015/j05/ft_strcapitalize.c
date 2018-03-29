/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 18:33:13 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/09 10:47:30 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == ' ')
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				str[i] = str[i] + 32;
			else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
				str[i] = str[i] + 32;
			else if (str[i-1] >= '0' && str[i - 1] <= '9')
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
