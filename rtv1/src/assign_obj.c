/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:12:13 by goarga            #+#    #+#             */
/*   Updated: 2016/04/28 20:32:35 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		assign_cone(t_rt *rt, char **split, int i)
{
	rt->obj[i].type = split[0][0];
	rt->obj[i].cone.co.y = ft_atoi(split[1]);
	rt->obj[i].cone.co.x = ft_atoi(split[2]);
	rt->obj[i].cone.co.z = ft_atoi(split[3]);
	rt->obj[i].cone.dir.y = ft_atoi(split[4]);
	rt->obj[i].cone.dir.x = ft_atoi(split[5]);
	rt->obj[i].cone.dir.z = ft_atoi(split[6]);
	rt->obj[i].cone.radius = ft_atoi(split[7]);
	rt->obj[i].cone.angle = ft_atoi(split[8]);
	rt->obj[i].col.r = ft_atoi(split[9]);
	rt->obj[i].col.b = ft_atoi(split[10]);
	rt->obj[i].col.g = ft_atoi(split[11]);
	rt->obj[i].col.a = ft_atoi(split[12]);
}

void		assign_cilinder(t_rt *rt, char **split, int i)
{
	rt->obj[i].type = split[0][0];
	rt->obj[i].cil.co.y = ft_atoi(split[1]);
	rt->obj[i].cil.co.x = ft_atoi(split[2]);
	rt->obj[i].cil.co.z = ft_atoi(split[3]);
	rt->obj[i].cil.dir.y = ft_atoi(split[4]);
	rt->obj[i].cil.dir.x = ft_atoi(split[5]);
	rt->obj[i].cil.dir.z = ft_atoi(split[6]);
	rt->obj[i].cil.radius = ft_atoi(split[7]);
	rt->obj[i].col.r = ft_atoi(split[8]);
	rt->obj[i].col.b = ft_atoi(split[9]);
	rt->obj[i].col.g = ft_atoi(split[10]);
	rt->obj[i].col.a = ft_atoi(split[11]);
}

void		assign_sphere(t_rt *rt, char **split, int i)
{
	rt->obj[i].type = split[0][0];
	rt->obj[i].sph.co.y = ft_atoi(split[1]);
	rt->obj[i].sph.co.x = ft_atoi(split[2]);
	rt->obj[i].sph.co.z = ft_atoi(split[3]);
	rt->obj[i].sph.radius = ft_atoi(split[4]);
	rt->obj[i].col.r = ft_atoi(split[5]);
	rt->obj[i].col.g = ft_atoi(split[6]);
	rt->obj[i].col.b = ft_atoi(split[7]);
	rt->obj[i].col.a = ft_atoi(split[8]);
}

void		assign_plane(t_rt *rt, char **split, int i)
{
	rt->obj[i].type = split[0][0];
	rt->obj[i].pln.co.y = ft_atoi(split[1]);
	rt->obj[i].pln.co.x = ft_atoi(split[2]);
	rt->obj[i].pln.co.z = ft_atoi(split[3]);
	rt->obj[i].pln.norm.y = ft_atoi(split[4]);
	rt->obj[i].pln.norm.x = ft_atoi(split[5]);
	rt->obj[i].pln.norm.z = ft_atoi(split[6]);
	rt->obj[i].col.r = ft_atoi(split[7]);
	rt->obj[i].col.g = ft_atoi(split[8]);
	rt->obj[i].col.b = ft_atoi(split[9]);
	rt->obj[i].col.a = ft_atoi(split[10]);
}

void		assign_main(t_rt *rt, char **split, int i)
{
	if (split[0][0] == 's')
		assign_sphere(rt, split, i);
	else if (split[0][0] == 'p')
		assign_plane(rt, split, i);
	else if (split[0][0] == 'c')
		assign_cilinder(rt, split, i);
	else if (split[0][0] == 'k')
		assign_cone(rt, split, i);
}
