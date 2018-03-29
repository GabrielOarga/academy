/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btrack_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 20:24:40 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:30:13 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const int	g_line[4] = {-1, 0, 1, 0};
const int	g_col[4] = {0, 1, 0, -1};

static	void	next(t_elem *a, int pos)
{
	a->hash++;
	a->index++;
	a->i += g_line[pos];
	a->j += g_col[pos];
}

static	void	prev(t_elem *a, int pos)
{
	a->index++;
	a->i -= g_line[pos];
	a->j -= g_col[pos];
}

static	void	put_reverse_letter(char **t_el, int pos, t_elem *a, int *pp)
{
	if (pos == 2)
		(*t_el)[a->index] = 'U';
	if (pos == 3)
		(*t_el)[a->index] = 'R';
	if (pos == 0)
		(*t_el)[a->index] = 'D';
	if (pos == 1)
		(*t_el)[a->index] = 'L';
	prev(a, pos);
	*pp = 0;
}

static	void	put_letter(char **this_element, int pos, t_elem *anexe, int *pp)
{
	if (pos == 0)
		(*this_element)[anexe->index] = 'U';
	if (pos == 1)
		(*this_element)[anexe->index] = 'R';
	if (pos == 2)
		(*this_element)[anexe->index] = 'D';
	if (pos == 3)
		(*this_element)[anexe->index] = 'L';
	next(anexe, pos);
	*pp = 1;
}

void			directions_back(char **el, char **mat, char **aux, t_elem *a)
{
	int	pos;
	int pp;

	pos = 0;
	while (pos < 4)
	{
		if (a->i + g_line[pos] >= 0 && a->j + g_col[pos] >= 0
			&& a->i + g_line[pos] < 4 && a->j + g_col[pos] < 4
			&& mat[a->i + g_line[pos]][a->j + g_col[pos]] == '#')
		{
			if (aux[a->i + 1 + g_line[pos]][a->j + 1 + g_col[pos]] != '1')
			{
				aux[a->i + 1 + g_line[pos]][a->j + 1 + g_col[pos]] = '1';
				put_letter(el, pos, a, &pp);
				directions_back(el, mat, aux, a);
			}
			if (pp == 1)
				put_reverse_letter(el, pos, a, &pp);
		}
		pos++;
	}
	(*el)[a->index] = '\0';
}
