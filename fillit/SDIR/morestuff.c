/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morestuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:04:29 by goarga            #+#    #+#             */
/*   Updated: 2016/01/16 00:22:23 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*save_line(char *tetriminos, char *line)
{
	char	*aux;

	aux = ft_strjoin(tetriminos, line);
	aux = ft_strjoin(aux, "*");
	free(tetriminos);
	tetriminos = aux;
	return (tetriminos);
}

void	init_elem(t_elem *elem)
{
	elem->i = 0;
	elem->j = 0;
	elem->pp = 0;
	elem->index = 0;
	elem->hash = 1;
}

void	exit_program(void)
{
	ft_putstr("error\n");
	exit(1);
}
