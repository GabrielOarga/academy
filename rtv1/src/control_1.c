/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 09:56:25 by goarga            #+#    #+#             */
/*   Updated: 2016/03/24 19:59:06 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		clear_image(t_rt *rt)
{
	if (rt->a.clear_image_init == 1)
		mlx_destroy_image(rt->mlx_id, rt->img_id);
}

void		init_image(t_rt *rt)
{
	rt->a.clear_image_init = 1;
	rt->img_id = mlx_new_image(rt->mlx_id, W_WIDTH, W_HEIGHT);
	rt->data = NULL;
	rt->data = mlx_get_data_addr(rt->img_id, &rt->a.bpp,
			&rt->a.lsize, &rt->a.endian);
}

void		draw_image(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx_id, rt->win_id, rt->img_id, 0, 0);
}

int			rt_controler(t_rt *rt)
{
	clear_image(rt);
	init_image(rt);
	rt_main(rt);
	draw_image(rt);
	return (0);
}

void		expose_main(t_rt *rt)
{
	mlx_expose_hook(rt->win_id, rt_controler, rt);
}
