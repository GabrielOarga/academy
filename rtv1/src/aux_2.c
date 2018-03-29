/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:23:06 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 16:24:19 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect3		vectsub_v3(t_vect3 v1, t_vect3 v2)
{
	t_vect3		retur;

	retur.x = v1.x - v2.x;
	retur.y = v1.y - v2.y;
	retur.z = v1.z - v2.z;
	return (retur);
}

t_vect3		vectadd_v3(t_vect3 v1, t_vect3 v2)
{
	t_vect3		retur;

	retur.x = v1.x + v2.x;
	retur.y = v1.y + v2.y;
	retur.z = v1.z + v2.z;
	return (retur);
}

double		dotprod_v3(t_vect3 v1, t_vect3 v2)
{
	double	prod;
	double	x;
	double	y;
	double	z;

	x = v1.x * v2.x;
	y = v1.y * v2.y;
	z = v1.z * v2.z;
	prod = x + y + z;
	return (prod);
}

double		vlen_v3(t_vect3 v)
{
	double	vlen;

	vlen = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (vlen);
}

t_vect3		vnorm_v3(t_vect3 v)
{
	double	vlen;

	vlen = vlen_v3(v);
	v.x = v.x / vlen;
	v.y = v.y / vlen;
	v.z = v.z / vlen;
	return (v);
}
