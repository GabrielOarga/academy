/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_correction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:01:56 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 18:30:35 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calc_offset_y(int row, int col)
{
	if (row < 25 && col < 25)
		return (2);
	else
		return (1.9);
}

void	get_offset_z(t_env *env)
{
	int		row;
	int		col;

	row = 0;
	while (row < env->mat.row)
	{
		col = 0;
		while (col < env->mat.col)
		{
			if (env->mat.matrix[row][col] > env->trig.offset_z)
				env->trig.offset_z = env->mat.matrix[row][col];
			col++;
		}
		row++;
	}
}

float	calc_offset_z(int z)
{
	if (z > -25 && z < 25)
		return (0.1);
	else if (z > -50 && z < 50)
		return (0.05);
	else
		return (0.01);
}
