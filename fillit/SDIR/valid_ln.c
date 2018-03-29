/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 20:27:16 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:36:21 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	valid_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int			check_line(char *line)
{
	if (ft_strlen(line) != 4)
		exit_program();
	if (!valid_line(line))
		exit_program();
	return (1);
}

int			check_newline(char *line)
{
	if (line[0] != '\0')
		exit_program();
	return (1);
}
