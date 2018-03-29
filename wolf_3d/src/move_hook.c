/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 23:10:30 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 21:14:58 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_fwd_bck(t_wolf *w)
{
	if (w->k.forward == 1)
	{
		if (w->map.height[(int)(w->p.posx + w->v.dirx *
					0.09)][(int)(w->p.posy)] == 0)
			w->p.posx += w->v.dirx * 0.09;
		if (w->map.height[(int)(w->p.posx)][(int)(w->p.posy +
					w->v.diry * 0.09)] == 0)
			w->p.posy += w->v.diry * 0.09;
	}
	if (w->k.back == 1)
	{
		if (w->map.height[(int)(w->p.posx - w->v.dirx *
					0.09)][(int)(w->p.posy)] == 0)
			w->p.posx -= w->v.dirx * 0.09;
		if (w->map.height[(int)(w->p.posx)][(int)(w->p.posy -
					w->v.diry * 0.09)] == 0)
			w->p.posy -= w->v.diry * 0.09;
	}
}

void		key_rotate(t_wolf *w)
{
	if (w->k.rot_left == 1)
	{
		w->v.olddirx = w->v.dirx;
		w->v.dirx = w->v.dirx * cos(w->v.ang) - w->v.diry * sin(w->v.ang);
		w->v.diry = w->v.diry * cos(w->v.ang) + w->v.olddirx * sin(w->v.ang);
		w->v.oldplanex = w->v.planex;
		w->v.planex = w->v.planex * cos(w->v.ang) - w->v.planey * sin(w->v.ang);
		w->v.planey = w->v.planey * cos(w->v.ang) +
			w->v.oldplanex * sin(w->v.ang);
	}
	if (w->k.rot_right == 1)
	{
		w->v.olddirx = w->v.dirx;
		w->v.dirx = w->v.dirx * cos(-w->v.ang) - w->v.diry * sin(-w->v.ang);
		w->v.diry = w->v.diry * cos(-w->v.ang) + w->v.olddirx * sin(-w->v.ang);
		w->v.oldplanex = w->v.planex;
		w->v.planex = w->v.planex * cos(-w->v.ang) -
			w->v.planey * sin(-w->v.ang);
		w->v.planey = w->v.planey * cos(-w->v.ang) +
			w->v.oldplanex * sin(-w->v.ang);
	}
}

void		movehook(t_wolf *w)
{
	move_fwd_bck(w);
	key_rotate(w);
}
