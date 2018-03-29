/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 09:56:16 by goarga            #+#    #+#             */
/*   Updated: 2016/04/03 20:50:47 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_mlx(t_rt *rt)
{
	rt->mlx_id = mlx_init();
	rt->win_id = mlx_new_window(rt->mlx_id, W_WIDTH, W_HEIGHT, "raytracer v1");
}

void		init_vectors(t_rt *rt)
{
	rt->v.orig.x = 0;
	rt->v.orig.y = 0;
	rt->v.orig.z = 0;
	rt->v.rayorig.x = 0;
	rt->v.rayorig.y = 0;
	rt->v.rayorig.z = 0;
	rt->v.dir.x = 0;
	rt->v.dir.y = 0;
	rt->v.dir.z = -2;
	rt->v.lumorig.x = 0;
	rt->v.lumorig.y = 0;
	rt->v.lumorig.z = 0;
}

void		init_param(t_rt *rt)
{
	rt->a.min_dist = 0;
	rt->data_index = 0;
	rt->obj[rt->obj_index].hit = 0;
	rt->obj[rt->obj_index].lhit = 0;
	rt->a.clear_image_init = 0;
	init_vectors(rt);
}
