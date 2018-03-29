/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 12:26:30 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 21:11:40 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			kphook(int keyhook, t_wolf *w)
{
	if (keyhook == 126)
		w->k.forward = 1;
	if (keyhook == 125)
		w->k.back = 1;
	if (keyhook == 123)
		w->k.rot_left = 1;
	if (keyhook == 124)
		w->k.rot_right = 1;
	if (keyhook == 53)
		w->k.exit = 1;
	if (keyhook == 15)
		w->k.reset = 1;
	if (keyhook == 43)
		w->k.contrastdown = 1;
	if (keyhook == 47)
		w->k.contrastup = 1;
	if (keyhook == 44)
		w->k.blurtoggle = 1;
	return (0);
}

int			krhook(int keyhook, t_wolf *w)
{
	if (keyhook == 126)
		w->k.forward = 0;
	if (keyhook == 125)
		w->k.back = 0;
	if (keyhook == 123)
		w->k.rot_left = 0;
	if (keyhook == 124)
		w->k.rot_right = 0;
	if (keyhook == 53)
		w->k.exit = 0;
	if (keyhook == 15)
		w->k.reset = 0;
	if (keyhook == 43)
		w->k.contrastdown = 0;
	if (keyhook == 47)
		w->k.contrastup = 0;
	if (keyhook == 44)
		w->k.blurtoggle = 0;
	return (0);
}

void		hook_controler(t_wolf *w)
{
	mlx_hook(w->win_id, 2, (1L << 0), kphook, w);
	mlx_hook(w->win_id, 3, (1L << 1), krhook, w);
	mlx_loop_hook(w->mlx_id, wolf_control, w);
	mlx_loop(w->mlx_id);
}
