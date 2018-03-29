/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:59:35 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 22:53:56 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_param		*p;

	p = (t_param*)malloc(sizeof(t_param));
	usage_check(p, argc, argv[1]);
	param_init(p);
	p->mlx_id = mlx_init();
	p->window_id = mlx_new_window(p->mlx_id, W_WIDTH, W_HEIGHT, "fractol");
	mlx_expose_hook(p->window_id, fractol_controller, p);
	mlx_key_hook(p->window_id, keyhook_main, p);
	mlx_mouse_hook(p->window_id, mouse_hook, p);
	mlx_hook(p->window_id, 6, (1L << 6), loop_hook, p);
	mlx_loop(p->mlx_id);
}
