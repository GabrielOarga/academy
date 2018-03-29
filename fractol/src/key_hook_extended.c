/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_extended.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 22:33:56 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:28:33 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		make_vomit(int keyhook, t_param *p)
{
	if (keyhook == 8)
	{
		if (p->ok == 0)
		{
			if (p->aux.vomit == 4)
				p->ok = 1;
			else
				p->aux.vomit += 1;
		}
		if (p->ok == 1)
		{
			if (p->aux.vomit == 1)
				p->ok = 0;
			else
				p->aux.vomit -= 1;
		}
	}
}

void		switch_color(int keyhook, t_param *p)
{
	if (keyhook == 7)
	{
		if (p->aux.color_switch == 0)
			p->aux.color_switch = 1;
		else if (p->aux.color_switch == 1)
			p->aux.color_switch = 0;
	}
}
