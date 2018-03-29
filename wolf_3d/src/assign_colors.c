/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:58:49 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 21:10:30 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		assign_col1(t_wolf *w)
{
	w->addr[w->addr_index + 0] = 255 * w->d.contrast;
	w->addr[w->addr_index + 1] = 178 * w->d.contrast;
	w->addr[w->addr_index + 2] = 120 * w->d.contrast;
	w->addr[w->addr_index + 3] = w->d.blur;
}

void		assign_col2(t_wolf *w)
{
	w->addr[w->addr_index + 0] = 169 * w->d.contrast;
	w->addr[w->addr_index + 1] = 255 * w->d.contrast;
	w->addr[w->addr_index + 2] = 120 * w->d.contrast;
	w->addr[w->addr_index + 3] = w->d.blur;
}

void		assign_col3(t_wolf *w)
{
	w->addr[w->addr_index + 0] = 120 * w->d.contrast;
	w->addr[w->addr_index + 1] = 255 * w->d.contrast;
	w->addr[w->addr_index + 2] = 178 * w->d.contrast;
	w->addr[w->addr_index + 3] = w->d.blur;
}

void		assign_col4(t_wolf *w)
{
	w->addr[w->addr_index + 0] = 255 * w->d.contrast;
	w->addr[w->addr_index + 1] = 232 * w->d.contrast;
	w->addr[w->addr_index + 2] = 120 * w->d.contrast;
	w->addr[w->addr_index + 3] = w->d.blur;
}

void		assign_colors(t_wolf *w)
{
	if (w->d.color == 1)
		assign_col1(w);
	if (w->d.color == 2)
		assign_col2(w);
	if (w->d.color == 3)
		assign_col3(w);
	if (w->d.color == 4)
		assign_col4(w);
}
