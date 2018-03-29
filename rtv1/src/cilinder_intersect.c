/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cilinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:48:37 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 11:04:25 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_hit_c(t_obj *obj, int *hit)
{
	if (obj->orth.discr < 0)
		*hit = 0;
	else
		*hit = 1;
}

void		calc_dist_c(t_obj *obj, double *d0, double *d1)
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

void		calc_control_c(int sel, t_obj *obj, t_rt *rt)
{
	if (sel == 0)
	{
		calc_hit_c(obj, &obj->hit);
		calc_dist_c(obj, &obj->d0, &obj->d1);
	}
	else if (sel == 1)
	{
		calc_hit_c(obj, &rt->obj[rt->obj_index].lhit);
		calc_dist_c(obj, &rt->obj[rt->obj_index].ld0,
				&rt->obj[rt->obj_index].ld1);
	}
}

void		calc_cilin_intersect(int sel, t_vect3 ray, t_obj *obj, t_rt *rt)
{
	t_vect3		cilorig;
	t_vect3		ncildir;
	t_vect3		ryxcd;
	t_vect3		coxcd;

	if (sel == 0)
		cilorig = vectsub_v3(rt->v.orig, obj->cil.co);
	else
		cilorig = vectsub_v3(rt->v.isect, obj->cil.co);
	ncildir = vnorm_v3(obj->cil.dir);
	ryxcd = crossprod_v3(ray, ncildir);
	coxcd = crossprod_v3(cilorig, ncildir);
	obj->orth.a = dotprod_v3(ryxcd, ryxcd);
	obj->orth.b = 2 * dotprod_v3(coxcd, ryxcd);
	obj->orth.c = dotprod_v3(coxcd, coxcd) - obj->cil.radius * obj->cil.radius;
	obj->orth.discr = (obj->orth.b * obj->orth.b) -
		4 * (obj->orth.a * obj->orth.c);
	calc_control_c(sel, obj, rt);
}
