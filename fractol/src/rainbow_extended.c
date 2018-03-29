/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 22:57:06 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:00:57 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_set_rainbow(t_param *p, int iter)
{
	if (p->aux.color_switch == 0)
		slow_rainbow(p, iter);
	else
		fast_rainbow(p, iter);
}
