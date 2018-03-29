/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:42:34 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 20:57:26 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_assign_color(t_param *p, int iter)
{
	if (iter == p->aux.max_iter)
		color_set_black(p);
	else
		color_set_rainbow(p, iter);
}

void		julia_calc_iter(t_param *p, double x, double y)
{
	double	a;
	double	b;
	double	aux;
	int		iter;

	a = x;
	b = y;
	iter = 0;
	while (((a * a + b * b) <= 4) && (iter < p->aux.max_iter))
	{
		aux = a * a - b * b + p->aux.julia_x;
		b = 2 * a * b + p->aux.julia_y;
		a = aux;
		iter++;
	}
	julia_assign_color(p, iter);
}

void		julia_get_xy(t_param *p, double row, double col)
{
	double	x;
	double	y;

	p->aux.julia_x = -0.7 * p->aux.mouse_move_x;
	p->aux.julia_y = 0.27015 * p->aux.mouse_move_y;
	x = ((col - p->aux.mouse_x) / (250 * p->aux.zoom));
	y = ((row - p->aux.mouse_y) / (250 * p->aux.zoom));
	julia_calc_iter(p, x, y);
}

void		julia_main(t_param *p)
{
	int		row;
	int		col;

	row = 0;
	while (row < W_HEIGHT)
	{
		col = 0;
		while (col < W_WIDTH)
		{
			julia_get_xy(p, (double)row, (double)col);
			col++;
		}
		row++;
	}
}
