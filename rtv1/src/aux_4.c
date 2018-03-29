/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:16:01 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 11:00:08 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		to_deg(double rad)
{
	return (rad * 180.0 / M_PI);
}

double		to_rad(double deg)
{
	return (deg * M_PI / 180);
}
