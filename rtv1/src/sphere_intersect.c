/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:00:21 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 11:37:10 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_hit_s(t_obj *obj, int *hit)
{
	if (obj->orth.discr < 0)
		*hit = 0;
	else
		*hit = 1;
}

void		calc_dist_s(t_obj *obj, double *d0, double *d1)
{
	double		aux;

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

void		calc_control_s(int sel, t_obj *obj, t_rt *rt)
{
	if (sel == 1)
	{
		calc_hit_s(obj, &rt->obj[rt->obj_index].lhit);
		calc_dist_s(obj, &rt->obj[rt->obj_index].ld0,
				&rt->obj[rt->obj_index].ld1);
	}
	if (sel == 0)
	{
		calc_hit_s(obj, &obj->hit);
		calc_dist_s(obj, &obj->d0, &obj->d1);
	}
}

void		calc_sphere_intersect(int sel, t_vect3 ray, t_obj *obj, t_rt *rt)
{
	t_vect3	nsph;
	t_vect3 sph2;

	if (sel == 0)
		sph2 = obj->sph.co;
	else
		sph2 = vectsub_v3(obj->sph.co, rt->v.isect);
	nsph = vectsub_v3(rt->v.orig, sph2);
	obj->orth.a = dotprod_v3(ray, ray);
	obj->orth.b = 2 * dotprod_v3(ray, nsph);
	obj->orth.c = dotprod_v3(nsph, nsph) -
		(obj->sph.radius * obj->sph.radius * 3);
	obj->orth.discr = (obj->orth.b * obj->orth.b) -
		(4 * obj->orth.a * obj->orth.c);
	calc_control_s(sel, obj, rt);
}
