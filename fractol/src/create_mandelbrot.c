/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:13:19 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 20:47:59 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_assign_color(t_param *p, int iter)
{
	if (iter == p->aux.max_iter)
		color_set_black(p);
	else
		color_set_rainbow(p, iter);
}

void		mandelbrot_calc_iter(t_param *p, double x, double y)
{
	double	a;
	double	b;
	double	aux;
	int		iter;

	a = 0;
	b = 0;
	iter = 0;
	while (((a * a + b * b) <= 4) && (iter < p->aux.max_iter))
	{
		aux = a * a - b * b + x;
		b = 2 * a * b + y;
		a = aux;
		iter++;
	}
	mandelbrot_assign_color(p, iter);
}

void		mandelbrot_get_xy(t_param *p, double row, double col)
{
	double	x;
	double	y;

	x = ((col - p->aux.mouse_x) / (250 * p->aux.zoom));
	y = ((row - p->aux.mouse_y) / (250 * p->aux.zoom));
	mandelbrot_calc_iter(p, x, y);
}

void		mandelbrot_main(t_param *p)
{
	int		row;
	int		col;

	row = 0;
	while (row < W_HEIGHT)
	{
		col = 0;
		while (col < W_WIDTH)
		{
			mandelbrot_get_xy(p, (double)row, (double)col);
			col++;
		}
		row++;
	}
}
