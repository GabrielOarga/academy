/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:13:00 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:00:01 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(int keyhook, t_param *p)
{
	if (keyhook == 15)
	{
		p->ok = 0;
		p->aux.vomit = 1;
		p->aux.color_switch = 0;
		p->aux.stop_julia = 0;
		p->aux.toggle = 0;
		p->aux.mouse_move_y = 0;
		p->aux.mouse_move_x = 0;
		p->col.index = 15;
		p->aux.zoom = 1;
		p->aux.zoom_index = 0;
		p->aux.mouse_x = W_WIDTH / 2;
		p->aux.mouse_y = W_HEIGHT / 2;
	}
}

void	translate(int keyhook, t_param *p)
{
	if (keyhook == 124)
		p->aux.mouse_x -= 100;
	if (keyhook == 123)
		p->aux.mouse_x += 100;
	if (keyhook == 125)
		p->aux.mouse_y -= 100;
	if (keyhook == 126)
		p->aux.mouse_y += 100;
}

void	color_reset(int keyhook, t_param *p)
{
	if (keyhook == 17)
		p->col.index = 15;
}

void	color_shift(int keyhook, t_param *p)
{
	if (keyhook == 43 && p->col.index <= 255)
		p->col.index += 5;
	if (keyhook == 47 && p->col.index >= 0)
		p->col.index -= 5;
}

int		keyhook_main(int keyhook, t_param *p)
{
	if (keyhook == 53)
		exit(1);
	if (keyhook == 50 && p->aux.toggle == 0)
	{
		p->aux.stop_julia = 1;
		p->aux.toggle = 1;
	}
	else if (keyhook == 50 && p->aux.toggle == 1)
	{
		p->aux.stop_julia = 0;
		p->aux.toggle = 0;
	}
	switch_color(keyhook, p);
	make_vomit(keyhook, p);
	translate(keyhook, p);
	color_reset(keyhook, p);
	color_shift(keyhook, p);
	reset(keyhook, p);
	fractol_controller(p);
	return (0);
}
