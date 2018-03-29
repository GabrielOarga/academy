/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:41:06 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 21:11:01 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		contrast(t_wolf *w)
{
	if (w->k.contrastup == 1)
	{
		if (w->d.contrast < 2.0)
			w->d.contrast += 0.1;
	}
	if (w->k.contrastdown == 1)
	{
		if (w->d.contrast > 0)
			w->d.contrast -= 0.1;
	}
	if (w->k.blurtoggle == 1)
		w->d.blur = 200;
	else if (w->k.blurtoggle == 0)
		w->d.blur = 0;
}

void		kh_exit_reset(t_wolf *w)
{
	if (w->k.exit == 1)
		exit(0);
	if (w->k.reset == 1)
	{
		w->v.ang = ANGLE;
		w->p.posx = POSX;
		w->p.posy = POSY;
		w->v.dirx = DIRX;
		w->v.diry = DIRY;
		w->v.planex = PLANEX;
		w->v.planey = PLANEY;
		w->d.blur = 0;
		w->d.contrast = 1;
	}
}

void		keyhook(t_wolf *w)
{
	contrast(w);
	kh_exit_reset(w);
}
