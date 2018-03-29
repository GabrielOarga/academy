/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:25:32 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 20:23:01 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_light_intersection(t_rt *rt)
{
	rt->obj_index2 = 0;
	rt->obj[rt->obj_index].lhit = 0;
	while (rt->obj_index2 < rt->obj_count)
	{
		if (rt->obj[rt->obj_index].lhit == 0)
			if (rt->obj_index != rt->obj_index2)
			{
				if (rt->obj[rt->obj_index2].type == 's')
					calc_sphere_intersect(1, rt->v.lum,
							&rt->obj[rt->obj_index2], rt);
				if (rt->obj[rt->obj_index2].type == 'p')
					calc_plane_intersect(1, rt->v.lum,
							&rt->obj[rt->obj_index2], rt);
				if (rt->obj[rt->obj_index2].type == 'c')
					calc_cilin_intersect(1, rt->v.lum,
							&rt->obj[rt->obj_index2], rt);
				if (rt->obj[rt->obj_index2].type == 'k')
					calc_cone_intersect(1, rt->v.lum,
							&rt->obj[rt->obj_index2], rt);
			}
		if (rt->obj[rt->obj_index].ld1 < 0 || rt->obj[rt->obj_index].ld0 < 0 ||
	(int)rt->obj[rt->obj_index].ld0 > (int)rt->obj[rt->obj_index].lumdist)
			rt->obj[rt->obj_index].lhit = 0;
		rt->obj_index2 += 1;
	}
}

void		normele_vietii(t_rt *rt)
{
	t_vect3		a;
	double		scalar;
	double		r;
	double		h;

	a.x = 0;
	a.y = rt->v.isect.y - rt->obj[rt->obj_index].cone.co.y;
	a.z = rt->v.isect.z - rt->obj[rt->obj_index].cone.co.z;
	scalar = vlen_v3(a);
	h = cos(to_rad(rt->obj[rt->obj_index].cone.angle)) * scalar;
	r = sin(to_rad(rt->obj[rt->obj_index].cone.angle)) * scalar;
	a = vnorm_v3(a);
	rt->v.norm.x = r / h;
	rt->v.norm.y = a.y * h / r;
	rt->v.norm.z = a.z * h / r;
	if (rt->v.isect.x > rt->obj[rt->obj_index].cone.co.x)
		rt->v.norm.x = rt->v.norm.x * -1;
}

void		calc_light_angle(t_rt *rt)
{
	t_vect3		a;
	t_vect3		b;

	rt->v.isect = ivsmult_v3(rt->v.ray, rt->obj[rt->obj_index].d0);
	if (rt->obj[rt->obj_index].type == 's')
		rt->v.norm = vectsub_v3(rt->v.isect, rt->obj[rt->obj_index].sph.co);
	if (rt->obj[rt->obj_index].type == 'p')
		rt->v.norm = vectsub_v3(rt->v.orig, rt->obj[rt->obj_index].pln.norm);
	if (rt->obj[rt->obj_index].type == 'c')
	{
		a = vectsub_v3(rt->v.isect, rt->obj[rt->obj_index].cil.co);
		b = crossprod_v3(a, rt->obj[rt->obj_index].cil.dir);
		rt->v.norm = crossprod_v3(rt->obj[rt->obj_index].cil.dir, b);
	}
	if (rt->obj[rt->obj_index].type == 'k')
		normele_vietii(rt);
	rt->v.norm = vnorm_v3(rt->v.norm);
	rt->obj[rt->obj_index].lumdist =
		vlen_v3(vectsub_v3(rt->v.lumorig, rt->v.isect));
	rt->v.lum = vnorm_v3(vectsub_v3(rt->v.lumorig, rt->v.isect));
	rt->obj[rt->obj_index].ang = dotprod_v3(rt->v.lum, rt->v.norm);
}

void		calc_shading(t_rt *rt)
{
	calc_light_angle(rt);
	calc_light_intersection(rt);
}
