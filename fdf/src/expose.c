/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:28:55 by goarga            #+#    #+#             */
/*   Updated: 2016/03/04 20:32:14 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose(t_env *env)
{
	mlx_clear_window(env->init_ptr, env->window_id);
	seg(env);
	get_pixel_poz(env);
	draw_stuff(env);
	draw_legend(env);
	return (0);
}

void	draw_legend(t_env *env)
{
	mlx_string_put(env->init_ptr, env->window_id, 5, 5, rainbow(env),
			"LEGEND:");
	mlx_string_put(env->init_ptr, env->window_id, 15, 25, rainbow(env),
			"\033[34mTRANSLATION:\033[0m ARROW KEYS !reversed! (zoom in for best effect)");
	mlx_string_put(env->init_ptr, env->window_id, 15, 45, rainbow(env),
			"ZOOM IN:\"+\", ZOOM OUT: \"-\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, 65, rainbow(env),
			"INCREASE HS: \">\", DECREASE HS \"<\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, 85, rainbow(env),
			"COLOR CHANGE: CYCLE THROUGH \"1-6\", EXTREME RAINBOW:\"0\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, 125, rainbow(env),
			"CLOSE MAP: \"ESC\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, 145, rainbow(env),
			"RESET MAP: \"R\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, 165, rainbow(env),
			"TOGGLE PRECISION MODE ON/OFF: \"P\"");
	mlx_string_put(env->init_ptr, env->window_id, 15, W_HEIGHT - 40,
			rainbow(env),
			"don't press: \"?\" it does nothing");
}

void	reset(t_env *env)
{
	env->trig.dynamic_offset_x = 0;
	env->trig.dynamic_offset_y = 0;
	env->trig.zoom_scale = 1;
	env->trig.height_scale = 1;
	env->trig.color = 1;
	env->trig.prec = 0;
	env->trig.seg = 0;
}

void	seg(t_env *env)
{
	char	*segme;

	segme = NULL;
	if (env->trig.seg == 0)
		segme = (char*)malloc(sizeof(char) * 3);
	segme[0] = 's';
	segme[1] = 'e';
	segme[2] = 'g';
}
