/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 19:46:28 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 21:21:36 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		calc_init_dist(t_wolf *w)
{
	if (w->v.raydirx < 0)
	{
		w->p.stepx = -1;
		w->p.initdistx = (w->p.rayposx - w->p.mapx) * w->p.deltax;
	}
	else
	{
		w->p.stepx = 1;
		w->p.initdistx = (w->p.mapx + 1.0 - w->p.rayposx) * w->p.deltax;
	}
	if (w->v.raydiry < 0)
	{
		w->p.stepy = -1;
		w->p.initdisty = (w->p.rayposy - w->p.mapy) * w->p.deltay;
	}
	else
	{
		w->p.stepy = 1;
		w->p.initdisty = (w->p.mapy + 1.0 - w->p.rayposy) * w->p.deltay;
	}
}

void		get_raystep(t_wolf *w, int col)
{
	w->p.camerax = 2 * col / (double)W_WIDTH - 1;
	w->p.rayposx = w->p.posx;
	w->p.rayposy = w->p.posy;
	w->v.raydirx = w->v.dirx + w->v.planex * w->p.camerax;
	w->v.raydiry = w->v.diry + w->v.planey * w->p.camerax;
	w->p.mapx = (int)w->p.rayposx;
	w->p.mapy = (int)w->p.rayposy;
	w->p.deltax = sqrt(1 + (w->v.raydiry * w->v.raydiry) /
			(w->v.raydirx * w->v.raydirx));
	w->p.deltay = sqrt(1 + (w->v.raydirx * w->v.raydirx) /
			(w->v.raydiry * w->v.raydiry));
	calc_init_dist(w);
}

void		diff_analysis(t_wolf *w)
{
	w->p.distx = w->p.initdistx;
	w->p.disty = w->p.initdisty;
	while (w->p.wallhit == 0)
	{
		if (w->p.distx < w->p.disty)
		{
			w->p.distx += w->p.deltax;
			w->p.mapx += w->p.stepx;
			w->p.wallside = 0;
		}
		else
		{
			w->p.disty += w->p.deltay;
			w->p.mapy += w->p.stepy;
			w->p.wallside = 1;
		}
		if (w->map.height[w->p.mapx][w->p.mapy] > 0)
			w->p.wallhit = 1;
	}
}

void		get_wall_height(t_wolf *w)
{
	if (w->p.wallside == 0)
		w->p.walldist = (w->p.mapx - w->p.rayposx +
				(1 - w->p.stepx) / 2) / w->v.raydirx;
	else if (w->p.wallside == 1)
		w->p.walldist = (w->p.mapy - w->p.rayposy +
				(1 - w->p.stepy) / 2) / w->v.raydiry;
	w->p.wallheight = (int)(W_HEIGHT / w->p.walldist);
	w->d.drawstart = W_HEIGHT / 2 - w->p.wallheight / 2;
	if (w->d.drawstart < 0)
		w->d.drawstart = 0;
	w->d.drawend = w->d.drawstart + w->p.wallheight;
	if (w->d.drawend > W_HEIGHT)
		w->d.drawend = W_HEIGHT;
}

void		wolf_main(t_wolf *w)
{
	int		col;

	col = 0;
	while (col < W_WIDTH)
	{
		get_raystep(w, col);
		diff_analysis(w);
		get_wall_height(w);
		get_rainbow(w, col);
		w->p.wallhit = 0;
		col += 1;
	}
}
