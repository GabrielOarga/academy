/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:07:28 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 21:07:56 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_hook(int x, int y, t_param *p)
{
	if (p->aux.stop_julia == 0)
	{
		p->aux.mouse_move_x = (x - p->aux.julia_x) / 250;
		p->aux.mouse_move_y = (y - p->aux.julia_y) / 250;
	}
	fractol_controller(p);
	return (0);
}
