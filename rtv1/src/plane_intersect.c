/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 20:49:24 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:44:17 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_visibility(t_vect3 ray, t_obj *obj, t_rt *rt)
{
	t_vect3		pnorm;
	t_vect3		porig;

	pnorm = vnorm_v3(obj->pln.norm);
	porig = vectsub_v3(rt->v.orig, obj->pln.co);
	if (dotprod_v3(ray, pnorm) <= 0.001)
		obj->hit = 0;
	else
	{
		obj->hit = 1;
		obj->d0 = ft_absd(dotprod_v3(vectsub_v3(rt->v.orig, porig), pnorm) /
				dotprod_v3(ray, pnorm));
		obj->d1 = obj->d0;
	}
}

void		calc_plane_shading(t_vect3 ray, t_obj *obj, t_rt *rt)
{
	t_vect3		pnorm;
	t_vect3		porig;

	pnorm = vnorm_v3(obj->pln.norm);
	porig = vectsub_v3(rt->v.isect, obj->pln.co);
	if (dotprod_v3(ray, pnorm) <= 0.001)
		rt->obj[rt->obj_index].lhit = 0;
	else
	{
		rt->obj[rt->obj_index].lhit = 1;
		rt->obj[rt->obj_index].ld0 = dotprod_v3(vectsub_v3(rt->v.orig, porig),
				pnorm) / dotprod_v3(ray, pnorm);
		rt->obj[rt->obj_index].ld1 = rt->obj[rt->obj_index].ld0;
	}
}

void		calc_plane_intersect(int sel, t_vect3 ray, t_obj *obj, t_rt *rt)
{
	if (sel == 0)
		calc_visibility(ray, obj, rt);
	else if (sel == 1)
		calc_plane_shading(ray, obj, rt);
}
