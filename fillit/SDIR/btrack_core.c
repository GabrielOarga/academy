/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btrack_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:47:31 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:29:55 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		back(char **mat, int n, int shapei)
{
	t_coord		c;

	c.i = 0;
	while (c.i < n)
	{
		c.j = 0;
		while (c.j < n)
		{
			g_cshape = shapei;
			if (put_shape(mat, c, n, g_shapes[shapei]))
			{
				if (shapei + 1 == count_shapes(g_shapes))
				{
					print_matrix(mat, n);
					exit(0);
				}
				if (count_spaces(mat, n) <= n * n - count_shapes(g_shapes) * 4)
					back(mat, n, shapei + 1);
			}
			g_cshape = shapei;
			clear_shape(mat, c, n, g_shapes[shapei]);
			c.j++;
		}
		c.i++;
	}
}
