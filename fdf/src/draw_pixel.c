/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 21:13:41 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 19:07:40 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_stuff(t_env *env)
{
	int		row;
	int		col;

	row = 0;
	while (row < env->mat.row)
	{
		col = 0;
		while (col < env->mat.col)
		{
			if (col < env->mat.col - 1)
				draw_line(env, (env->poz)[row][col], (env->poz)[row][col + 1]);
			if (row < env->mat.row - 1)
				draw_line(env, (env->poz)[row][col], (env->poz)[row + 1][col]);
			col++;
		}
		row++;
	}
}

static float	max(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

static float	calc(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void			draw_line(t_env *env, t_poz x, t_poz y)
{
	float	i;
	float	a;
	float	b;
	float	div;

	i = 0;
	div = max(calc(x.co_x - y.co_x), calc(x.co_y - y.co_y));
	while (i <= div)
	{
		a = x.co_x + ((i / div) * (y.co_x - x.co_x));
		b = x.co_y + ((i / div) * (y.co_y - x.co_y));
		mlx_pixel_put(env->init_ptr, env->window_id, a, b, rainbow(env));
		i++;
	}
}
