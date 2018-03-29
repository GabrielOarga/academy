/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 10:38:12 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 20:20:16 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_mlx(t_wolf *w)
{
	w->mlx_id = mlx_init();
	w->win_id = mlx_new_window(w->mlx_id, W_WIDTH, W_HEIGHT, "wolf3d");
}

void		init_param2(t_wolf *w)
{
	w->k.forward = 0;
	w->k.back = 0;
	w->k.rot_left = 0;
	w->k.rot_right = 0;
	w->k.reset = 0;
	w->k.exit = 0;
}

void		init_param(t_wolf *w)
{
	w->v.ang = ANGLE;
	w->p.posx = POSX;
	w->p.posy = POSY;
	w->v.dirx = DIRX;
	w->v.diry = DIRY;
	w->v.planex = PLANEX;
	w->v.planey = PLANEY;
	w->p.wallhit = 0;
	w->a.kpress = 0;
	w->map.row = 0;
	w->map.col = 0;
	w->addr_index = 0;
	w->a.clear = 0;
	w->d.color = 1;
	w->d.blur = 0;
	w->d.contrast = 1;
	init_param2(w);
}
