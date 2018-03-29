/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:57:39 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 18:29:50 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colors(int keyhook, t_env *env)
{
	if (keyhook == 18)
		env->trig.color = 1;
	if (keyhook == 19)
		env->trig.color = 2;
	if (keyhook == 20)
		env->trig.color = 3;
	if (keyhook == 21)
		env->trig.color = 4;
	if (keyhook == 23)
		env->trig.color = 5;
	if (keyhook == 22)
		env->trig.color = 6;
	if (keyhook == 29)
		env->trig.color = 69;
}

void	removethis(int keyhook, t_env *env)
{
	if (keyhook == 50)
		env->trig.seg = 1;
}
