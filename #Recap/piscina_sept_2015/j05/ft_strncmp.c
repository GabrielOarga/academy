/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 17:44:35 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/08 17:55:14 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}
