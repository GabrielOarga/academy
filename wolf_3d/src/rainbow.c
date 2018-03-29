/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 23:53:47 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 20:50:18 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		assign_rainbow(t_wolf *w)
{
	if (w->p.wallside == 0)
	{
		if (w->p.stepx < 0)
			w->d.color = 1;
		if (w->p.stepx > 0)
			w->d.color = 2;
	}
	if (w->p.wallside == 1)
	{
		if (w->p.stepy < 0)
			w->d.color = 3;
		if (w->p.stepy > 0)
			w->d.color = 4;
	}
	assign_colors(w);
}

void		assign_rainbow_floor(t_wolf *w)
{
	w->addr[w->addr_index + 0] = 243;
	w->addr[w->addr_index + 1] = 255;
	w->addr[w->addr_index + 2] = 227;
	w->addr[w->addr_index + 3] = w->d.blur;
}

void		get_rainbow(t_wolf *w, int col)
{
	int		line;

	line = w->d.drawstart;
	w->addr_index = (col * 4) + (4 * W_WIDTH) * line;
	while (line < W_HEIGHT)
	{
		if (line < w->d.drawend)
			assign_rainbow(w);
		else if (line >= w->d.drawend)
			assign_rainbow_floor(w);
		line++;
		w->addr_index += W_WIDTH * 4;
	}
	w->addr_index = 0;
}
