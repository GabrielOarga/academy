/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 11:52:35 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 19:00:48 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clear_wolf(t_wolf *w)
{
	if (w->a.clear == 1)
		mlx_destroy_image(w->mlx_id, w->img_id);
}

void		init_wolf(t_wolf *w)
{
	int		bpp;
	int		lsize;
	int		endian;
	int		x;
	int		y;

	w->a.clear = 1;
	w->img_id = mlx_xpm_file_to_image(w->mlx_id, "src/epic3.xpm", &x, &y);
	w->addr = NULL;
	w->addr = mlx_get_data_addr(w->img_id, &bpp, &lsize, &endian);
}

void		draw_wolf(t_wolf *w)
{
	mlx_put_image_to_window(w->mlx_id, w->win_id, w->img_id, 0, 0);
}

int			wolf_control(t_wolf *w)
{
	keyhook(w);
	movehook(w);
	clear_wolf(w);
	init_wolf(w);
	wolf_main(w);
	draw_wolf(w);
	return (0);
}

void		wolf_expose(t_wolf *w)
{
	mlx_expose_hook(w->win_id, wolf_control, w);
}
