/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:30:05 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 19:09:16 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_scale(t_env *env)
{
	if (W_WIDTH > W_HEIGHT)
	{
		if ((W_HEIGHT / env->mat.col) < (W_HEIGHT / env->mat.row))
			env->trig.scale = W_HEIGHT / (env->mat.row * 2) *
				env->trig.zoom_scale;
		else
			env->trig.scale = W_HEIGHT / (env->mat.col * 2) *
				env->trig.zoom_scale;
	}
	else
	{
		if ((W_WIDTH / env->mat.row) < (W_WIDTH / env->mat.col))
			env->trig.scale = W_WIDTH / (env->mat.row * 2);
		else
			env->trig.scale = W_WIDTH / (env->mat.col * 2);
	}
}

float	calc_coord_x(t_env *env, int row, int col)
{
	float co_x;

	env->trig.static_offset_x = (env->mat.row * 0.866 * env->trig.scale +
			env->mat.col * 0.5 * env->trig.scale) / 2 -
		env->mat.row * 0.5 * env->trig.scale -
		env->trig.dynamic_offset_x;
	co_x = W_WIDTH / 2 - env->trig.static_offset_x +
		env->trig.scale * col - env->trig.scale * row;
	return (co_x);
}

float	calc_coord_y(t_env *env, int row, int col)
{
	float co_y;

	env->trig.static_offset_y = (env->mat.row * 0.866 * env->trig.scale +
			env->mat.col * 0.5 * env->trig.scale) /
		calc_offset_y(env->mat.row, env->mat.col) -
		env->trig.dynamic_offset_y;
	co_y = W_HEIGHT / 2 - env->trig.static_offset_y +
		env->trig.scale * 0.5 * col + env->trig.scale * row -
		(env->trig.scale * calc_offset_z(env->trig.offset_z))
		* env->mat.matrix[row][col] * env->trig.height_scale;
	return (co_y);
}

void	get_pixel_poz(t_env *env)
{
	int col;
	int row;

	row = 0;
	get_scale(env);
	get_offset_z(env);
	env->poz = (t_poz**)malloc(sizeof(t_poz*) * env->mat.row);
	while (row < env->mat.row)
	{
		col = 0;
		env->poz[row] = (t_poz*)malloc(sizeof(t_poz) * env->mat.col);
		while (col < env->mat.col)
		{
			env->poz[row][col].co_x = calc_coord_x(env, row, col);
			env->poz[row][col].co_y = calc_coord_y(env, row, col);
			col++;
		}
		row++;
	}
}
