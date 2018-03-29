/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 21:40:41 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/05 23:24:49 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		verif(char *str, int i)
{
	if (str[i] == '-')
	{
		return (-1);
	}
	else
	{
		if (str[i] == '+')
			return (1);
		else
			return (0);
	}
}

int		verif_cif(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}

int		sarire(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '0')
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int nr;
	int p;

	i = 0;
	nr = 0;
	i = sarire(str);
	if (verif_cif(str, i) == 1)
		p = 1;
	else
	{
		p = verif(str, i);
		i++;
	}
	while (verif_cif(str, i) == 1)
	{
		nr = nr * 10 + (str[i] - '0');
		i++;
	}
	return (nr * p);
}
