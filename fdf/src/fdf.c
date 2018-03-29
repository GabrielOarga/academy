/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:42:26 by goarga            #+#    #+#             */
/*   Updated: 2016/03/05 20:08:57 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->trig.zoom_scale = 1;
	env->trig.height_scale = 1;
	env->trig.color = 1;
	env->trig.prec = 0;
	env->trig.seg = 0;
	validate_arguments(argc);
	read_matrix(argv[1], env);
	env->init_ptr = mlx_init();
	env->window_id = mlx_new_window(env->init_ptr, W_WIDTH, W_HEIGHT, "fdf");
	mlx_expose_hook(env->window_id, expose, env);
	mlx_key_hook(env->window_id, keyhook, env);
	mlx_loop(env);
	return (0);
}
