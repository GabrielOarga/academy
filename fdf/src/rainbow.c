/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:48:30 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 19:09:43 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rainbow(t_env *env)
{
	char	*rainbow;

	rainbow = NULL;
	rainbow = (char*)malloc(sizeof(char) * 4);
	if (env->trig.color < 4)
		rainbow = get_color(rainbow, env->trig.color);
	else if (env->trig.color < 7)
		rainbow = get_color_2(rainbow, env->trig.color);
	else if (env->trig.color == 69)
		return ((int)rainbow);
	return (*((int*)rainbow));
}

char	*get_color(char *rainbow, int color)
{
	if (color == 1)
	{
		rainbow[0] = 255;
		rainbow[1] = 255;
		rainbow[2] = 255;
	}
	else if (color == 2)
	{
		rainbow[0] = 7;
		rainbow[1] = 65;
		rainbow[2] = 255;
	}
	else if (color == 3)
	{
		rainbow[0] = 255;
		rainbow[1] = 147;
		rainbow[2] = 20;
	}
	rainbow[3] = 0;
	return (rainbow);
}

char	*get_color_2(char *rainbow, int color)
{
	if (color == 4)
	{
		rainbow[0] = 27;
		rainbow[1] = 255;
		rainbow[2] = 173;
	}
	if (color == 5)
	{
		rainbow[0] = 147;
		rainbow[1] = 20;
		rainbow[2] = 255;
	}
	if (color == 6)
	{
		rainbow[0] = 180;
		rainbow[1] = 130;
		rainbow[2] = 70;
	}
	rainbow[3] = 0;
	return (rainbow);
}
