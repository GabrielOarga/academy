/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:03:33 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:10:00 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_color(t_param *p)
{
	p->col.b = 255;
	p->col.g = 0;
	p->col.r = 0;
}

void		color_set_black(t_param *p)
{
	int	k;

	k = 0;
	while (k <= 3)
	{
		p->addr[p->aux.addr_index + k] = 0;
		k++;
	}
	p->aux.addr_index += 4;
}

void		assign_colors(t_param *p)
{
	p->addr[p->aux.addr_index] = p->col.b;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = p->col.g;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = p->col.r;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = 0;
	p->aux.addr_index += 1;
	reset_color(p);
}

void		slow_rainbow(t_param *p, int iter)
{
	while (iter >= 0)
	{
		if (p->col.b > 0 && p->col.g < 255 && p->col.r == 0)
		{
			p->col.b -= p->col.index;
			p->col.g += p->col.index;
		}
		else if (p->col.g > 0 && p->col.r < 255 && p->col.b == 0)
		{
			p->col.g -= p->col.index;
			p->col.r += p->col.index;
		}
		else if (p->col.r > 0 && p->col.b < 255 && p->col.g == 0)
		{
			p->col.r -= p->col.index;
			p->col.b += p->col.index;
		}
		else
			reset_color(p);
		iter -= 1;
	}
	assign_colors(p);
}

void		fast_rainbow(t_param *p, int iter)
{
	p->addr[p->aux.addr_index] = 255 - iter * 25 * p->aux.vomit;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = 255 - iter * 53 * p->aux.vomit;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = 255 - iter * 123 * p->aux.vomit;
	p->aux.addr_index += 1;
	p->addr[p->aux.addr_index] = 0;
	p->aux.addr_index += 1;
}
