/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 09:58:17 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 20:16:21 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_intersection(t_rt *rt, double row, double col)
{
	rt->v.vers.x = 2 * row / (double)W_HEIGHT - 1;
	rt->v.vers.y = 2 * col / (double)W_WIDTH - 1;
	rt->v.ray.x = -rt->v.dir.x + rt->v.vers.x;
	rt->v.ray.y = -rt->v.dir.y + rt->v.vers.y;
	rt->v.ray.z = -rt->v.dir.z + 0;
	rt->v.ray = vnorm_v3(rt->v.ray);
	if (rt->obj[rt->obj_index].type == 's')
		calc_sphere_intersect(0, rt->v.ray, &rt->obj[rt->obj_index], rt);
	if (rt->obj[rt->obj_index].type == 'p')
		calc_plane_intersect(0, rt->v.ray, &rt->obj[rt->obj_index], rt);
	if (rt->obj[rt->obj_index].type == 'c')
		calc_cilin_intersect(0, rt->v.ray, &rt->obj[rt->obj_index], rt);
	if (rt->obj[rt->obj_index].type == 'k')
		calc_cone_intersect(0, rt->v.ray, &rt->obj[rt->obj_index], rt);
}

void		prea_multe_linii_boss_sa_le_fut_de_norme(t_rt *rt, int i, int j)
{
	while (rt->obj_index < rt->obj_count)
	{
		calc_intersection(rt, (double)i, (double)j);
		if (rt->obj[rt->obj_index].hit == 1)
		{
			calc_shading(rt);
			draw_scene(rt);
		}
		rt->obj_index += 1;
	}
}

void		rt_main(t_rt *rt)
{
	int		i;
	int		j;

	i = 0;
	rt->a.clear_image_init = 1;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			rt->obj_index = 0;
			prea_multe_linii_boss_sa_le_fut_de_norme(rt, i, j);
			rt->data_index += 4;
			rt->a.min_dist = 0;
			++j;
		}
		++i;
	}
	rt->data_index = 0;
}
