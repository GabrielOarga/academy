/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:21:40 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 11:00:42 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_absd(double nr)
{
	if (nr < 0)
		return (nr * -1);
	else
		return (nr);
}

t_vect3		ivsmult_v3(t_vect3 v, double scal)
{
	t_vect3		retur;

	retur.x = v.x * scal;
	retur.y = v.y * scal;
	retur.z = v.z * scal;
	return (retur);
}

t_vect3		vsmult_v3(double scal, t_vect3 v)
{
	t_vect3		retur;

	retur.x = v.x * scal;
	retur.y = v.y * scal;
	retur.z = v.z * scal;
	return (retur);
}

t_vect3		crossprod_v3(t_vect3 v1, t_vect3 v2)
{
	t_vect3		retur;

	retur.x = v1.y * v2.z - v1.z * v2.y;
	retur.y = v1.z * v2.x - v1.x * v2.z;
	retur.z = v1.x * v2.y - v1.y * v2.x;
	return (retur);
}

t_vect3		vrotate_v3(t_vect3 v, double angle)
{
	t_vect3		rv;

	rv.x = v.x * cos(angle) + v.z * sin(angle);
	rv.y = v.y;
	rv.z = (v.x * sin(angle) * -1) + v.z * cos(angle);
	return (rv);
}
