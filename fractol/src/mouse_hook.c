/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:07:08 by goarga            #+#    #+#             */
/*   Updated: 2016/02/28 22:16:59 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_zoom(int button, double x, double y, t_param *p)
{
	if (button == 5 && p->aux.zoom_index < 75)
	{
		p->aux.mouse_x = x - (x - p->aux.mouse_x) * 1.5;
		p->aux.mouse_y = y - (y - p->aux.mouse_y) * 1.5;
		p->aux.zoom *= 1.5;
		p->aux.max_iter += 5;
		p->aux.zoom_index += 1;
	}
	if (button == 4 && p->aux.zoom_index > 0)
	{
		p->aux.mouse_x = x - (x - p->aux.mouse_x) / 1.5;
		p->aux.mouse_y = y - (y - p->aux.mouse_y) / 1.5;
		p->aux.zoom /= 1.5;
		p->aux.max_iter -= 5;
		p->aux.zoom_index -= 1;
	}
}

int		mouse_hook(int button, int x, int y, t_param *p)
{
	scroll_zoom(button, x, y, p);
	fractol_controller(p);
	return (0);
}
