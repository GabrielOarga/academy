/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:06:19 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 16:22:52 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_exit(int keyhook, t_env *env)
{
	if (keyhook == 53)
	{
		ft_putstr("RUNTIME ERROR ... Just kidding you closed the program");
		exit(0);
	}
	if (keyhook == 15)
		reset(env);
}

void	translate(int keyhook, t_env *env)
{
	float	mult;

	if (env->trig.prec == 0)
		mult = 0;
	else
		mult = 15;
	if (keyhook == 123)
		env->trig.dynamic_offset_x = env->trig.dynamic_offset_x + 15 +
			(env->trig.zoom_scale * 15) - mult;
	if (keyhook == 124)
		env->trig.dynamic_offset_x = env->trig.dynamic_offset_x - 15 -
			(env->trig.zoom_scale * 15) + mult;
	if (keyhook == 126)
		env->trig.dynamic_offset_y = env->trig.dynamic_offset_y + 15 +
			(env->trig.zoom_scale * 15) - mult;
	if (keyhook == 125)
		env->trig.dynamic_offset_y = env->trig.dynamic_offset_y - 15 -
			(env->trig.zoom_scale * 15) + mult;
}

void	height_scale(int keyhook, t_env *env)
{
	float	mult;

	if (env->trig.prec == 0)
		mult = 0;
	else
		mult = 0.75;
	if (keyhook == 47)
		env->trig.height_scale = (env->trig.height_scale + 1) - mult;
	if (keyhook == 43)
		env->trig.height_scale = (env->trig.height_scale - 1) + mult;
}

void	zoom(int keyhook, t_env *env)
{
	float	mult;

	if (env->trig.prec == 0)
		mult = 0.75;
	else
		mult = 1;
	if (keyhook == 24)
		env->trig.zoom_scale = env->trig.zoom_scale * 1.2 / mult;
	if (keyhook == 27)
		env->trig.zoom_scale = env->trig.zoom_scale * 0.8 * mult;
}

int		keyhook(int keyhook, t_env *env)
{
	if (keyhook == 35)
	{
		if (env->trig.prec == 0)
			env->trig.prec = 1;
		else
			env->trig.prec = 0;
	}
	removethis(keyhook, env);
	colors(keyhook, env);
	reset_exit(keyhook, env);
	height_scale(keyhook, env);
	zoom(keyhook, env);
	translate(keyhook, env);
	expose(env);
	return (0);
}
