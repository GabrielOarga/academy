/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 22:25:33 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:47:30 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_hit_k(t_obj *obj, int *hit)
{
	if (obj->orth.discr < 0)
		*hit = 0;
	else
		*hit = 1;
}

void		calc_dist_k(t_obj *obj, double *d0, double *d1)
{
	double	aux;

	aux = 0.0;
	if (obj->orth.discr == 0)
	{
		*d0 = obj->orth.b / obj->orth.a * (-0.5);
		*d1 = *d0;
	}
	else if (obj->orth.discr > 0)
	{
		*d0 = (obj->orth.b + sqrt(obj->orth.discr)) / obj->orth.a * (-0.5);
		*d1 = (obj->orth.b - sqrt(obj->orth.discr)) / obj->orth.a * (-0.5);
		if (ft_absd(*d0) > ft_absd(*d1))
		{
			aux = *d0;
			*d0 = *d1;
			*d1 = aux;
		}
	}
}

void		calc_control_k(int sel, t_obj *obj, t_rt *rt)
{
	if (sel == 0)
	{
		calc_hit_k(obj, &obj->hit);
		calc_dist_k(obj, &obj->d0, &obj->d1);
	}
	else if (sel == 1)
	{
		calc_hit_k(obj, &rt->obj[rt->obj_index].lhit);
		calc_dist_k(obj, &rt->obj[rt->obj_index].ld0,
				&rt->obj[rt->obj_index].ld1);
	}
}

void		sa_le_futa_dumnezo_de_norme(t_obj *obj, t_rt *rt, int sel)
{
	obj->orth.discr = (obj->orth.b * obj->orth.b) -
		(4 * obj->orth.a * obj->orth.c);
	calc_control_k(sel, obj, rt);
}

void		calc_cone_intersect(int sel, t_vect3 ray, t_obj *obj, t_rt *rt)
{
	t_vect3		corig;
	double		rxc;
	double		cxc;
	double		co;
	double		si;

	if (sel == 0)
		corig = vectsub_v3(rt->v.orig, obj->cone.co);
	else
		corig = vectsub_v3(rt->v.isect, obj->cone.co);
	rxc = dotprod_v3(ray, vnorm_v3(obj->cone.dir));
	cxc = dotprod_v3(corig, vnorm_v3(obj->cone.dir));
	co = cos(to_rad(obj->cone.angle)) * cos(to_rad(obj->cone.angle));
	si = sin(to_rad(obj->cone.angle)) * sin(to_rad(obj->cone.angle));
	obj->orth.a = co * dotprod_v3(vectsub_v3(ray, ivsmult_v3(vnorm_v3(
obj->cone.dir), rxc)), vectsub_v3(ray, ivsmult_v3(vnorm_v3(obj->cone.dir),
rxc))) - si * rxc * rxc;
	obj->orth.b = 2 * co * dotprod_v3(vectsub_v3(ray, ivsmult_v3(vnorm_v3(
obj->cone.dir), rxc)), vectsub_v3(corig, ivsmult_v3(vnorm_v3(obj->cone.dir),
cxc))) - 2 * si * rxc * cxc;
	obj->orth.c = co * dotprod_v3(vectsub_v3(corig, ivsmult_v3(vnorm_v3(
obj->cone.dir), cxc)), vectsub_v3(corig, ivsmult_v3(vnorm_v3(obj->cone.dir),
cxc))) - si * cxc * cxc;
	sa_le_futa_dumnezo_de_norme(obj, rt, sel);
}
