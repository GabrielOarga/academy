/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:50:36 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:48:28 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		calc_exposure(t_obj obj)
{
	double	exp;

	exp = 1;
	if (obj.lhit == 1)
		return (exp * 0.3 * obj.ang);
	return (exp * obj.ang);
}

void		check_min_dist(double min, double check, t_rt *rt)
{
	if (check >= min)
		return ;
	else
		rt->a.min_dist = check;
}

void		assign_colors(t_rt *rt, double b, double g, double r)
{
	if (b <= 0)
		b = 0;
	if (g <= 0)
		g = 0;
	if (r <= 0)
		r = 0;
	rt->data[rt->data_index + 0] = b;
	rt->data[rt->data_index + 1] = g;
	rt->data[rt->data_index + 2] = r;
	rt->data[rt->data_index + 3] = rt->obj[rt->obj_index].col.a;
}

void		draw_scene(t_rt *rt)
{
	int		b;
	int		g;
	int		r;
	double	exposure;

	if (rt->a.min_dist == 0)
		rt->a.min_dist = rt->obj[rt->obj_index].d0;
	else
		check_min_dist(rt->a.min_dist, rt->obj[rt->obj_index].d0, rt);
	if (rt->obj[rt->obj_index].hit != 0 && rt->a.min_dist >=
			rt->obj[rt->obj_index].d0)
	{
		exposure = calc_exposure(rt->obj[rt->obj_index]);
		b = rt->obj[rt->obj_index].col.b * exposure;
		g = rt->obj[rt->obj_index].col.g * exposure;
		r = rt->obj[rt->obj_index].col.r * exposure;
		assign_colors(rt, b, g, r);
	}
}
