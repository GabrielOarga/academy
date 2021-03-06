/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:52:12 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/09 09:38:28 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	if (s1[i] == s2[i] && s1[i] == '\0')
		return (0);
	else if (s1[i] > s2[i])
		return (s1[i] - s2[i]);
	else
		return (s2[i] - s1[i]);
}
