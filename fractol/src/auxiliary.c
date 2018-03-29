/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:08:16 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:24:22 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	param_init(t_param *p)
{
	p->ok = 0;
	p->aux.vomit = 1;
	p->aux.color_switch = 0;
	p->aux.toggle = 0;
	p->aux.stop_julia = 0;
	p->col.b = 255;
	p->col.g = 0;
	p->col.r = 0;
	p->col.index = 15;
	p->aux.zoom_index = 0;
	p->aux.ok = 0;
	p->aux.zoom = 1;
	p->aux.mouse_move_x = 0;
	p->aux.mouse_move_y = 0;
	p->aux.julia_x = W_WIDTH / 2;
	p->aux.julia_y = W_HEIGHT / 2;
	p->aux.mouse_x = W_WIDTH / 2;
	p->aux.mouse_y = W_HEIGHT / 2;
	p->aux.max_iter = 30;
	p->aux.addr_index = 0;
}

void	mlx_clear(t_param *p)
{
	if (p->aux.ok == 1)
	{
		mlx_clear_window(p->mlx_id, p->window_id);
		mlx_destroy_image(p->mlx_id, p->image_id);
		p->aux.addr_index = 0;
	}
	p->aux.ok = 1;
}

void	mlx_initialize(t_param *p)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	p->image_id = mlx_new_image(p->mlx_id, W_WIDTH, W_HEIGHT);
	p->addr = NULL;
	p->addr = mlx_get_data_addr(p->image_id,
			&bits_per_pixel, &size_line, &endian);
}

void	mlx_draw(t_param *p)
{
	mlx_put_image_to_window(p->mlx_id, p->window_id, p->image_id, 0, 0);
}
